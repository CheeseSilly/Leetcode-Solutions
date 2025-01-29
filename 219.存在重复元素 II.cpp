#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int n = nums.size();
    // abs(i-j)<=k
    // i<j,j-i<=k
    // nums[i]=nums[j]
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j <= k + i && j < n; j++) {
        if (nums[i] == nums[j]) {
          return true;
        }
      }
    }
    return false;
  }
};

class Solution2 {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int left = 0;
    int left_s = 0;
    int n = nums.size();
    for (int right = 0; right < n; right++) {
      while (left <= right) {
        if (nums[left] == nums[right] && left != right) {
          return true;
        }
        left++;
      }
      left = left_s;
      if (right - left == k) {
        left_s++;
        left = left_s;
      }
    }
    return false;
  }
};

class Solution3 {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++) {
      if (!st.insert(nums[i]).second) { // st 中有 nums[i]
        return true;
      }
      if (i >= k) {
        st.erase(nums[i - k]);
      }
    }
    return false;
  }
};
