#include <chrono>

template <typename T>
CalgoBenchLog& CalgoBenchLog::operator<<(const T& in) {
  stream << in;
  return *this;
}

template <typename T>
CalgoBenchLog& CalgoBenchLog::operator<<(const std::vector<T>& in) {
  stream << "vector: " << std::endl;
  for (int i = 0; i < in.size(); i++) {
    stream << i << ": " << in[i] << std::endl;
  }

  return *this;
}

template <typename T>
CalgoBenchLog& CalgoBenchLog::operator<<(const std::vector<std::vector<T>>& in) {
  stream << "vector: " << std::endl;
  for (int i = 0; i < in.size(); i++) {
    for (int j = 0; j < in[i].size(); j++) {
      if (j != 0) {
        stream << ", ";
      }
      stream << in[i][j];
    }
    stream << std::endl;
  }

  return *this;
}

template <typename Function, typename ...Args>
void CalgoBench::profile(const std::string& description, Function f, Args... args) {
  CBL << "Profiling: " << description;

  // One run
  auto oneRunStart = std::chrono::high_resolution_clock::now();
  auto output = f(args...);
  auto oneRunEnd = std::chrono::high_resolution_clock::now();
  auto oneRunDuration = std::chrono::duration_cast<std::chrono::microseconds>(oneRunEnd - oneRunStart);

  // Ten runs
  auto tenRunsStart = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 10; i++) {
    f(args...);
  }
  auto tenRunsEnd = std::chrono::high_resolution_clock::now();
  auto tenRunsDuration = std::chrono::duration_cast<std::chrono::microseconds>(tenRunsEnd - tenRunsStart);

  CBL << "Output:";
  CBL << output;
  CBL << "";

  CBL << "1 run took " << oneRunDuration.count() << "us";
  CBL << "10 runs took " << tenRunsDuration.count() << "us";
  CBL << "";
}
