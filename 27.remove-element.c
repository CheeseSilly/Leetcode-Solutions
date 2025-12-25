/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start
int removeElement(int *nums, int numsSize, int val) {
  int stackSize = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != val) {
      nums[stackSize++] = nums[i];
    }
  }
  return stackSize;
}
// @lc code=end
