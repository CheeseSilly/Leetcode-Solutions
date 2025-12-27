/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
int minSubArrayLen(int target, int *nums, int numsSize) {
  int res = INT_MAX;
  int l = 0, r = 0;
  int perSum = 0; // sum per window
  // res=r-l+1
  for (r = 0; r < numsSize; r++) {
    perSum += nums[r];
    while (perSum >= target) {
      res = fmin(res, r - l + 1);
      perSum -= nums[l++];
    }
  }
  return res == INT_MAX ? 0 : res;
}
// @lc code=end
