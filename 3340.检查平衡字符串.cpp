#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
  bool isBalanced(string num) {

    int odd = 0, even = 0;

    for (int i = 0; i < num.size(); i++) {
      if (i % 2 == 0) {
        even += num[i] - '0';
      }
      if (i % 2 == 1) {
        odd += num[i] - '0';
      }
    }
    return (even == odd) ? true : false;
  }
};
