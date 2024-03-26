#include "analysis.h"
#include <iostream>

void printHelp(const char *executableName){
    std::cout << executableName << " Usage : <macro|min|min> [custom consumed file path](optional)" << "\n" ;  
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
  std::cerr << "Insufficient arguments provided" << "\n";
  printHelp(argv[0]);
  return 1;
  }

  std::string consumedFilename = "consumed.json";

  if (argc == 3) {
    /* If consumedFilename is provided, use that. Otherwise fall back to`consumed.ini` */

   consumedFilename = argv[2];
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
