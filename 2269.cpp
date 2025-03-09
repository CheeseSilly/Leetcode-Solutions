#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
  int divisorSubstrings(int num, int k) {
    string s = to_string(num);
    int ans = 0;
    for (int i = k; i <= s.size(); i++) {
      int x = stoi(s.substr(i - k, k)); // 长为 k 的子串
      if (x > 0 && num % x == 0) {      // 子串能整除 num
        ans++;
      }
    }
    return ans;
  }
};
