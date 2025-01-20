#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findClosestNumber(vector<int> &nums) {
    int ans = nums[0];
    int flag = 0;
    for (auto i : nums) {
      int temp1 = abs(ans);
      int temp2 = abs(i);
      if (temp1 > min(temp1, temp2)) {
        ans = i;
      }
      if (ans + i == 0) {
        flag = 1;
      }
    }
    return flag == 0 ? ans : abs(ans);
  }
};