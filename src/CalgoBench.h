#ifndef CALGO_BENCH
#define CALGO_BENCH

// TODO: remove this
#ifndef CBL
#define CBL CalgoBenchLog()
#endif

#include <sstream>
#include <string>
#include <vector>

class CalgoBenchLog {
 public:
  ~CalgoBenchLog();

  template <typename T>
  CalgoBenchLog& operator<<(const T& in);

  template <typename T>
  CalgoBenchLog& operator<<(const std::vector<T>& in);

  template <typename T>
  CalgoBenchLog& operator<<(const std::vector<std::vector<T>>& in);


 private:
  std::ostringstream stream;
};



#include <chrono>

class CalgoBench {
 public:
  template <typename Function, typename ...Args>
  static void profile(const std::string& description, Function f, Args... args);
};

#include "CalgoBench.tpp"

#endif
