#ifndef LOADER_H
#define LOADER_H

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <mutex>
#include <string>

class Loader {
 private:
  static Loader *pinstance_;
  static std::mutex mutex_;

 protected:
  Loader(){};
  ~Loader(){};

 public:
  Loader(Loader &other) = delete;
  void operator=(const Loader &) = delete;
  static Loader *GetInstance();

  template <class Loadable>
  void load(Loadable &s, const char *filename) {
    std::ifstream ifs(filename);
    boost::archive::text_iarchive ia(ifs);
    ia >> s;
  }
};

#endif  //? LOADER_H