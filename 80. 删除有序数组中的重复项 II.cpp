#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    int index = 2;
    for (int i = 2; i < n; i++) {
      if (nums[i] != nums[index - 2]) {
        nums[index++] = nums[i];
      }
    }
    return min(n, index);
  }
};