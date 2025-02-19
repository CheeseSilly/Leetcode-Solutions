#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> evenOddBit(int n) {
    vector<int> ans(2, 0); // ans=[even,odd]
    int even = 0;
    int odd = 0;
    int flag = 0; // flag=index;
    while (n != 0) {
      int tmp = 0;
      tmp = n % 2;
      if (tmp == 1 && flag % 2 == 0) {
        even++;
      } else if (tmp == 1 && flag % 2 == 1) {
        odd++;
      }
      n /= 2;
      flag++;
    }
    ans[0] = even;
    ans[1] = odd;
    return ans;
  }
};