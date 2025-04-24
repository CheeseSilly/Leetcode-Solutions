#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  int countCompleteSubarrays(vector<int> &nums) {
    unordered_set<int> us(nums.begin(), nums.end());
    int k = us.size();
    int left = 0, ans = 0;
    unordered_map<int, int> um;
    // 找到不满足条件的left情况，则left-1之后的情况均满足，同时right向后走left-？前面的条件也均满足

    for (int x : nums) {
      um[x]++;
      while (um.size() == k) {
        int out = nums[left];
        if (--um[out] == 0) {
          um.erase(out);
        }
        left++;
      }
      ans += left;
    }
    return ans;
  }
};