#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    int left = 0;
    int ans = INT_MAX;
    int tmp = 0;
    int flag = 0;
    for (int right = 0; right < n; right++) {
      tmp |= nums[right];
      if (nums[right] >= k) {
        ans = min(ans, 1);
        flag = 1;
        break;
      }
      while (tmp >= k && left <= right) {
        ans = min(ans, right - left + 1);
        left++;
        tmp = 0;
        for (int i = right; i >= left; i--) {
          tmp |= nums[i];
        }
        flag = 1;
      }
    }
    if (flag == 0) {
      return -1;
    }
    return ans;
  }
};