#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    ans = left;
    if (ans >= nums.size()) {
      ans = nums.size() - 1;
    }
    return target == nums[ans] ? ans : -1;
  }
};