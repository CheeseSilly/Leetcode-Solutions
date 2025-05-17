#include <string>

class Solution {
public:
  bool isHappy(int n) {
    if (n == 1 || n == 7) {
      return true;
    } else if (n > 1 && n < 10 && n != 7) {
      return false;
    }
    std::string num = std::to_string(n);
    long long sum = 0;
    for (char c : num) {
      int digit = c - '0';
      sum += digit * digit;
    }
    return isHappy(sum);
  }
};