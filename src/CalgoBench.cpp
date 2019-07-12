#include "CalgoBench.h"

#include <iostream>

CalgoBenchLog::~CalgoBenchLog() {
  std::cout << stream.str() << std::endl;
}
