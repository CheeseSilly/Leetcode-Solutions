#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>

using namespace std;

class Solution {
public:
  int scoreOfString(string s) {
    int ans = 0;
    int pre = s[0] - '0';
    for (int i = 1; i < s.size(); i++) {
      int cnt = s[i] - '0';
      ans += abs(pre - cnt);
      pre = cnt;
    }
    return ans;
  }
};
