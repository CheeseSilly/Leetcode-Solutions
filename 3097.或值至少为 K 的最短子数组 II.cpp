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
    int base = 0;
    for (int right = 0; right < n; right++) {
      tmp |= nums[right];
      if (nums[right] >= k) {
        return 1;
      }
      while ((nums[left] | tmp) >= k && left <= right) {
        ans = min(ans, right - left + 1);
        left++;
        if (base < left) {
          for (int i = right - 1; i >= left; i--) {
            nums[i] |= nums[i + 1];
          }
          base = right;
          tmp = 0;
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