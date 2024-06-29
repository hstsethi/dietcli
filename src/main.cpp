#include "analysis.h"
#include "util.h"
#include <iostream>

void printHelp(const char *executableName) {
  std::cout << executableName
            << " Usage : <macro|min|min> [custom consumed file path](optional)"
            << "\n";
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Insufficient arguments" << "\n";
    printHelp(argv[0]);
    return 1;
  }

  std::string consumedFilename = "consumed.json";

  if (argc == 3) {
    /* If consumedFilename is provided, and the file is accessible, use that.
     * Otherwise fall back to`consumed.json` */

    if (checkFileExists(argv[2])) {
      consumedFilename = argv[2];
    }

    else {
      std::cerr << "No such file " << argv[2] << " falling back to consumed.json"
                << "\n";
      consumedFilename = "consumed.json";
    }
  }

  if (strcmp(argv[1], "macro") == 0) {

    compareMacro(consumedFilename);
  } else if (strcmp(argv[1], "min") == 0) {

    compareMinerals(consumedFilename);
  }

  else if (strcmp(argv[1], "vit") == 0) {
    compareVitamins(consumedFilename);

  } else {
    std::cerr << "Invalid arguments specified" << "\n";
    printHelp(argv[0]);
    return 1;
  }

  return 0;
}
