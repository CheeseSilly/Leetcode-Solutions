#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int l = 0;
    long long ans = 0;
    int sub_max = -1, sub_min = -1;
    int inval = -1;
    // nums[r]==minK,check sub_min==mink. keep index
    // nums[r]==maxK,check sub_max==maxK. keep index
    // val is in [sub_min,sub_max].if not,past subarray is fixed
    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] == minK) {
        sub_min = r;
      }
      if (nums[r] == maxK) {
        sub_max = r;
      }
      if (nums[r] > maxK || nums[r] < minK) {
        inval = r;
      }
      ans += max(min(sub_max, sub_min) - inval, 0);
    }
    cout << inval << endl;
    return ans;
  }
};