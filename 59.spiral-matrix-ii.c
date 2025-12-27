/*
 * @lc app=leetcode.cn id=59 lang=c
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
const int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes) {
  *returnSize = n;
  *returnColumnSizes = malloc(n * sizeof(int));
  int **ans = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    (*returnColumnSizes)[i] = n;
    ans[i] = calloc(n, sizeof(int));
  }
  int i = 0, j = 0, di = 0;
  for (int val = 1; val <= n * n; val++) {
    ans[i][j] = val;
    int x = i + DIRS[di][0];
    int y = j + DIRS[di][1];
    if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y]) {
      di = (di + 1) % 4;
    }
    i += DIRS[di][0];
    j += DIRS[di][1];
  }
  return ans;
}
// @lc code=end
