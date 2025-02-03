#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    // vector<int> nums0(nums.size()/2,0);
    // vector<int> nums1(nums.size()/2,0);
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if ((i % 2 == 0 && nums[i] % 2 == 0) ||
          (i % 2 == 1 && nums[i] % 2 == 1)) {
        // pass
        continue;
      } else {
        for (int j = i + 1; j < n; j++) {
          if (i % 2 == 0 && (j % 2 == 1 && nums[j] % 2 == 0)) {
            swap(nums[i], nums[j]);
          } else if (i % 2 == 1 && (j % 2 == 0 && nums[j] % 2 == 1)) {
            swap(nums[i], nums[j]);
          }
        }
      }
    }
    return nums;
  }
};

class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    int i = 0, j = 1;
    int n = nums.size();
    while (i < n) {
      if (nums[i] % 2 == 0) {
        i += 2;
      } else if (nums[j] % 2 == 1) {
        j += 2;
      } else {
        swap(nums[i], nums[j]);
        i += 2;
        j += 2;
      }
    }
    return nums;
  }
};