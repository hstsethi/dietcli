#include <fstream>
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <sstream> // For buffering the output before printing to stdout

void compareMacro(const std::string &consumedFilename) {
  std::ostringstream buffer;

  std::ifstream consumedFile(consumedFilename);
  rapidjson::IStreamWrapper consumedStream(consumedFile);
  rapidjson::Document consumed;
  consumed.ParseStream(consumedStream);

  std::ifstream rdiFile("rdi.json");
  rapidjson::IStreamWrapper rdiStream(rdiFile);
  rapidjson::Document rdi;
  rdi.ParseStream(rdiStream);

  std::string macronutrients[4] = {"Protein", "Carbs", "Fats", "Fiber"};

  for (const std::string &macro : macronutrients) {

    int rdiAmount = rdi["Macronutrients"][macro.c_str()].GetInt();
    int consumedAmount = consumed["Macronutrients"][macro.c_str()].GetInt();
    buffer << macro << "\t"
           << "RDI amount : " << rdiAmount << "\t"
           << "Consumed amount : " << consumedAmount << "\t"
           << "Remaining : " << rdiAmount - consumedAmount << "\n";
  }
  std::cout << buffer.str();
}

void compareMinerals(const std::string &consumedFilename) {
  std::ostringstream buffer;

  std::ifstream consumedFile(consumedFilename);
  rapidjson::IStreamWrapper consumedStream(consumedFile);
  rapidjson::Document consumed;
  consumed.ParseStream(consumedStream);

  std::ifstream rdiFile("rdi.json");
  rapidjson::IStreamWrapper rdiStream(rdiFile);
  rapidjson::Document rdi;
  rdi.ParseStream(rdiStream);

  std::string minerals[4] = {"Potassium", "Iron", "Sodium", "Magnesium"};

  for (const std::string &nutrient : minerals) {
    int consumedAmount = consumed["Minerals"][nutrient.c_str()].GetInt();
    int rdiAmount = rdi["Minerals"][nutrient.c_str()].GetInt();
    buffer << nutrient << "\t"
           << "RDI amount : " << rdiAmount << "\t"
           << "Consumed amount : " << consumedAmount << "\t"
           << "Remaining : " << rdiAmount - consumedAmount << "\n";
  }

  std::cout << buffer.str();
}

void compareVitamins(const std::string &consumedFilename) {
  std::ostringstream buffer;

  std::string vitamins[6] = {"A", "B12", "C", "D", "E", "K"};
  std::ifstream consumedFile(consumedFilename);
  rapidjson::IStreamWrapper consumedStream(consumedFile);
  rapidjson::Document consumed;
  consumed.ParseStream(consumedStream);

  std::ifstream rdiFile("rdi.json");
  rapidjson::IStreamWrapper rdiStream(rdiFile);
  rapidjson::Document rdi;
  rdi.ParseStream(rdiStream);

  for (const std::string &nutrient : vitamins) {
    int consumedAmount = consumed["Vitamins"][nutrient.c_str()].GetInt();
    int rdiAmount = rdi["Vitamins"][nutrient.c_str()].GetInt();
    buffer << nutrient << "\t"
           << "RDI amount : " << rdiAmount << "\t"
           << "Consumed amount : " << consumedAmount << "\t"
           << "Remaining : " << rdiAmount - consumedAmount << "\n";
  }
  std::cout << buffer.str();
}
