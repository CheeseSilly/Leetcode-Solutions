/*
 * @lc app=leetcode.cn id=977 lang=c
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize) {
  int *res = (int *)malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;
  int i = 0, j = numsSize - 1, p = numsSize - 1;
  while (p != -1) {
    int x = nums[i], y = nums[j];
    if (-x > y) {
      res[p] = x * x;
      i++;
      p--;
    } else {
      res[p] = y * y;
      j--;
      p--;
    }
  }
  return res;
}
// @lc code=end
