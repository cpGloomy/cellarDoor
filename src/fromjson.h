#ifndef FROMJSON_H
#define FROMJSON_H

#include <jsoncpp/json/json.h>

#include <tuple>
#include <type_traits>

template <typename Class, typename T>
struct Property {
  constexpr Property(T Class::*aMember, const char *aName)
      : member{aMember}, name{aName} {}

  using Type = T;

  T Class::*member;
  const char *name;
};

template <class T>
using decay_t = typename std::decay<T>::type;

template <bool B, class T = void>
using enable_if_t = typename std::enable_if<B, T>::type;

template <std::size_t iteration, typename T>
void doSetData(T &&object, const Json::Value &data) {
  constexpr auto property = std::get<iteration>(decay_t<T>::properties);
  using Type = typename decltype(property)::Type;
  object.*(property.member) = data[property.name].asString();
}

template <std::size_t iteration, typename T,
          enable_if_t<(iteration > 0)> * = nullptr>
void setData(T &&object, const Json::Value &data) {
  doSetData<iteration>(object, data);
  setData<iteration - 1>(object, data);
}

template <std::size_t iteration, typename T,
          enable_if_t<(iteration == 0)> * = nullptr>
void setData(T &&object, const Json::Value &data) {
  doSetData<iteration>(object, data);
}

template <typename T>
T fromJson(Json::Value data) {
  T object;

  setData<std::tuple_size<decltype(T::properties)>::value - 1>(object, data);

  return object;
}

#endif  //? FROMJSON_H