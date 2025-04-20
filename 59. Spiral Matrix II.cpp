#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    // need to turn side when arriving at the end of corner
    // corner:end and not visited

    // down,left,up,right...loop
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    vector<vector<int>> ans(n, vector(n, 0));

    int loop = n / 2;
    int mid = n / 2;
    int offset = 1; // shrink 1 size when touch the right edge. start is
                    // n-1,which is just the edge

    int x = 0;
    int y = 0;
    int count = 1;
    int i, j;
    while (loop--) {
      i = x;
      j = y;
      for (; j < n - offset; j++) {
        ans[i][j] = count++;
      }
      for (; i < n - offset; i++) {
        ans[i][j] = count++;
      }
      for (; j > y; j--) {
        ans[i][j] = count++;
      }
      for (; i > x; i--) {
        ans[i][j] = count++;
      }
      x++;
      y++;
      offset += 1;
    }
    if (n % 2) {
      ans[mid][mid] = count;
    }
    return ans;
  }
};