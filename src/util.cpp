#include "util.h"
#include <fstream>

bool checkFileExists(std::string filename) {
  std::ifstream file(filename.c_str());
  return file.good();
}
