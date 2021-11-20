#include <fstream>
#include <iostream>

#include "functions.hpp"
#include "utilities.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
              << std::endl;
    return 1;
  }
  std::ifstream ifs{argv[1]};
  // std::ifstream
  // ifs{"/home/vagrant/src/mp-dna-forensics-khushigupta07/src/data.csv"};
  std::map<std::string, std::vector<int>> dna_data;
  std::vector<std::string> givens;
  bool firstLine = true;
  for (std::string line; std::getline(ifs, line); line = "") {
    std::vector<std::string> temp_vect1 = utilities::get_substrs(line, ',');
    if (firstLine) {
      givens = temp_vect1;
    } else {
      std::vector<int> int_vector;
      for (int pos = 1; pos < (int)temp_vect1.size(); ++pos) {
        int_vector.push_back(std::stoi(temp_vect1.at(pos)));
      }
      dna_data[temp_vect1.at(0)] = int_vector;
    }
    firstLine = false;
  }
  std::cout << DNAMatch(dna_data, givens, argv[2]) << std::endl;
  return 0;
}