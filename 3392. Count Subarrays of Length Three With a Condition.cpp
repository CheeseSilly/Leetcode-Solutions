#include <vector>
using namespace std;
class Solution {
public:
  int countSubarrays(vector<int> &nums) {
    int ans = 0;
    int l = 0;
    int sum = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (r - l + 1 == 3) {
        if ((nums[l] + nums[r]) * 2 == nums[r - 1]) {
          ans++;
        }
        l++;
      }
    }
    return ans;
  }
};