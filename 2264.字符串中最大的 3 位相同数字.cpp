#include <bits/stdc++.h>
#include <string>

class Solution {
public:
  std::string largestGoodInteger(std::string num) {
    int n = num.size();
    std::string res = "";
    std::string temp = "";
    int left = 0;
    for (int right = 0; right < n; right++) {
      temp += num[right];
      if (right - left + 1 == 3) {
        if (temp[0] == temp[1] && temp[1] == temp[2] && temp[0] == temp[2]) {
          if (res == "") {
            res = temp.substr(0, 3);
          }
          if (temp > res) {
            res = temp.substr(0, 3);
          }
        }
        temp = temp.substr(1, 2);
        left++;
      }
    }
    return res;
  }
};
