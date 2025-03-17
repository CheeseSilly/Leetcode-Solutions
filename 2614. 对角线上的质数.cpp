#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return n >= 2; // 1 不是质数
  }

  int diagonalPrime(vector<vector<int>> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int n : {nums[i][i], nums[i][nums.size() - 1 - i]}) {
        if (n > ans && isPrime(n)) {
          ans = n;
        }
      }
    }
    return ans;
  }
};
