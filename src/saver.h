#ifndef SAVER_H
#define SAVER_H

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <mutex>

class Saver {
 private:
  static Saver *pinstance_;
  static std::mutex mutex_;

 protected:
  Saver(){};
  ~Saver(){};

 public:
  Saver(Saver &other) = delete;
  void operator=(const Saver &) = delete;
  static Saver *GetInstance();

  template <class Saveable>
  void save(const Saveable &s, const char *filename) {
    std::ofstream ofs(filename);
    boost::archive::text_oarchive oa(ofs);
    oa << s;
  }
};
#endif  //?SAVER_H