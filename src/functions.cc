#include "functions.hpp"

#include <iostream>

int GetMatches(std::string dna_sequence, std::string str) {
  int high_count = 0;
  int current_count = 0;
  for (int i = 0; i < (int)dna_sequence.length() - (int)str.length() + 1; i++) {
    std::string string_seg = dna_sequence.substr(i, str.length());
    if (string_seg == str) {
      current_count++;
      i += (int)str.length() - 1;
    } else {
      current_count = 0;
    }
    if (current_count >= high_count) {
      high_count = current_count;
    }
  }
  return high_count;
}

std::string DNAMatch(std::map<std::string, std::vector<int>> data_map,
                     std::vector<std::string> givens,
                     std::string dna_string) {
  std::string name;
  bool match = false;
  for (auto const& x : data_map) {
    // std::cout << x.second.at(0) + " " + x.second.at(1) + " " + x.second.at(2)
    // << std::endl;
    if (GetMatches(dna_string, givens.at(1)) == x.second.at(0) &&
        GetMatches(dna_string, givens.at(2)) == x.second.at(1) &&
        GetMatches(dna_string, givens.at(3)) == x.second.at(2)) {
      name = x.first;
      match = true;
    }
  }
  if (!match) {
    std::cout << "No match" << std::endl;
  }
  return name;
}