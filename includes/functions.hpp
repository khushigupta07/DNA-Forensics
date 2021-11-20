#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utilities.hpp"

int GetMatches(std::string dna_sequence, std::string str);
std::string DNAMatch(std::map<std::string, std::vector<int>> data_map,
                     std::vector<std::string> givens,
                     std::string dna_string);

#endif