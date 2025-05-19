#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res(2, 0);
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++) {
      if (um.contains(target - nums[i])) {
        res[0] = um[target - nums[i]];
        res[1] = i;
      }
      um[nums[i]] = i;
    }
    return res;
  }
};