#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    // find the max,and crop it.
    sort(nums.begin(), nums.end());
    int max = nums[nums.size() - 1];

    // l=最小划分后的最大值，即最小开销
    // r相反
    int l = 1;
    int r = max;
    //二分查，比mid小则无需划分，比mid大则划分，记录划分个数来限制maxOperations
    // if(sum>maxOperations),then
    // l+1,说明要划分到当前l所需划分个数>maxOperations
    // else,r=mid,说明当前划分个数小于等于maxoperations,缩小范围
    while (l < r) {
      int mid = (l + r) >> 1;
      int sum = 0;
      for (auto v : nums) {
        if (v > mid) {
          //上取整,[a/b]=[a-1/b]+1
          sum += (v - 1) / mid;
        }
      }
      if (sum > maxOperations) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};