#include <vector>

using namespace std;
class Solution {
  const int MOD = 1'000'000'007;

public:
  int numTilings(int n) {
    if (n == 1) {
      return 1;
    }
    vector<long long> f(n + 1);
    f[0] = f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++) {
      f[i] = (f[i - 1] * 2 + f[i - 3]) % MOD;
    }
    return f[n];
  }
};