#include <bits/stdc++.h>

using namespace std;
const int MOD = 1'000'000'007;
const int MX = 100'001;

long long f[MX], g[MX];

// except7||9(g(i)),others 3(f(i))
// f[i]=f[i-1]+f[i-2]+f[i-3];
// g[i]=g[i-1]+g[i-2]+g[i-3]+g[i-4]

int init = []() {
  f[0] = g[0] = 1;
  f[1] = g[1] = 1;
  f[2] = g[2] = 2;
  f[3] = g[3] = 4;
  for (int i = 4; i < MX; ++i) {
    f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
    g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD;
  }
  return 0;
}();

class Solution {
public:
  int countTexts(string pressedKeys) {
    int ans = 1;
    int cnt = 0;
    for (int i = 0; i < pressedKeys.length(); i++) {
      char c = pressedKeys[i];
      cnt++;
      if (i == pressedKeys.length() - 1 || c != pressedKeys[i + 1]) {
        ans = ans * (c != '7' && c != '9' ? f[cnt] : g[cnt]) % MOD;
        cnt = 0;
      }
    }
    return ans;
  }
};