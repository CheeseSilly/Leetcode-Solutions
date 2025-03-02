#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    // n=target/nums[i]
    // n=(target-nums[j])/nums[i]
    // 枚举每一个数,选了i后,子问题变为target-nums[i]
    vector<int> memo(target + 1, -1); // -1 表示没有计算过
    auto dfs = [&](this auto &&dfs, int i) {
      if (i == 0) { // 爬完了
        return 1;
      }
      int &res = memo[i]; // 注意这里是引用
      if (res != -1) {    // 之前计算过
        return res;
      }
      res = 0;
      for (int x : nums) {
        if (x <= i) {
          res += dfs(i - x);
        }
      }
      return res;
    };
    return dfs(target);
  }
};