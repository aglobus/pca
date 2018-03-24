#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

#define SIZE 50000

typedef struct {
  std::vector<double> dim1;
  std::vector<double> dim2;
} test_t;

std::vector<std::string> split(const std::string &s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> tokens;
  // Extract characters from ss and append them to item until delim or end while ss is valid
  while (std::getline(ss, item, delim)) {
    tokens.push_back(item);
  }
  return tokens;
}

void read_data(const char *filename, test_t &set) {
  std::ifstream file(filename, std::ios::in);
  for (std::string line; std::getline(file, line);) {
    std::vector<std::string> r = split(line, ',');
    set.dim1.push_back(::atof(r[0].c_str()));
    set.dim2.push_back(::atof(r[1].c_str()));
  }
}
