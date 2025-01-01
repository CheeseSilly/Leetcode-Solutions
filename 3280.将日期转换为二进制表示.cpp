#include <bitset>
#include <iostream>
#include <string>

class Solution {
public:
  std::string convertDateToBinary(std::string date) {
    return binary(std::stoi(date.substr(0, 4))) + "-" +
           binary(std::stoi(date.substr(5, 2))) + "-" +
           binary(std::stoi(date.substr(8, 2)));
  }

private:
  std::string binary(int x) {
    std::string s = std::bitset<32>(x).to_string();
    return s.substr(s.find('1'));
  }
};