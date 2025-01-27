#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    int base1 = 1;
    int base2 = 1;
    vector<int> c[100];
    // 1                        0
    // 1 1                      1
    // 1 2 1                    2
    for (int i = 0; i < rowIndex + 1; i++) {
      c[i].resize(i + 1, 1);
      for (int j = 1; j < i; j++) {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      }
    }
    return c[rowIndex];
  }
};