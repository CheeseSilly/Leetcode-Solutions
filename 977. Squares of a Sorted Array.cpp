#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int> &nums) {
    for (auto &i : nums) {
      i = i * i;
    }

    int i = 0;
    int j = nums.size() - 1;

    vector<int> ans(nums.size(), 0);
    int idx = nums.size() - 1;

    while (i <= j) {
      if (nums[i] < nums[j]) {
        ans[idx] = nums[j];
        j--;
      } else if (nums[i] >= nums[j]) {
        ans[idx] = nums[i];
        i++;
      }
      idx -= 1;
    }
    return ans;
  }
};
