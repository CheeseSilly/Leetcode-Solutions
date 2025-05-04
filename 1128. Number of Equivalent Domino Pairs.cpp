#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    int ans = 0;
    int cnt[10][10]{};
    for (auto &d : dominoes) {
      auto [a, b] = minmax(d[0], d[1]); // 保证 a <= b
      ans += cnt[a][b]++;
    }
    return ans;
  }
};