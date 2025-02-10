#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> ans(2, -1);
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == target) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      auto b = lower_bound(nums.begin(), nums.end(), target);
      auto e = upper_bound(nums.begin(), nums.end(), target);
      ans[0] = b - nums.begin();
      ans[1] = e - nums.begin();
    }
    return ans;
  }
};
