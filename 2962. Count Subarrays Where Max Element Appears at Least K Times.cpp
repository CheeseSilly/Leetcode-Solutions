#include <algorithm>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int max_x = ranges::max(nums);
    int cnt_mx = 0;
    long long ans = 0;
    int left = 0;
    for (auto x : nums) {
      cnt_mx += (x == max_x);
      // until [left,x] is not for k-size
      // so left-1 to 0 is all available
      while (cnt_mx == k) {
        cnt_mx -= (nums[left] == max_x);
        left++;
      }
      ans += left;
    }
    return ans;
  }
};