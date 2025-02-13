#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &position, int m) {
    int n = position.size();
    int l = 0;
    int r = 1e9 - 1;

    auto f = [&](int d) -> int {
      int cnt = 1, pre = position[0];
      for (int p : position) {
        if (p >= pre + d) {
          cnt++;
          pre = p;
        }
      }
      return cnt;
    };

    sort(position.begin(), position.end());
    // distance=|position(x)-position(y)|
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (f(mid) >= m) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }
};