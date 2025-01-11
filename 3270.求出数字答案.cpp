#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int generateKey(int num1, int num2, int num3) {
    vector<int> n1(4, 0);
    vector<int> n2(4, 0);
    vector<int> n3(4, 0);
    int ans = 0;
    n1[0] = num1 / 1000 % 10;
    n1[1] = num1 / 100 % 10;
    n1[2] = num1 / 10 % 10;
    n1[3] = num1 % 10;
    n2[0] = num2 / 1000 % 10;
    n2[1] = num2 / 100 % 10;
    n2[2] = num2 / 10 % 10;
    n2[3] = num2 % 10;
    n3[0] = num3 / 1000 % 10;
    n3[1] = num3 / 100 % 10;
    n3[2] = num3 / 10 % 10;
    n3[3] = num3 % 10;
    ans = min(min(n1[0], n2[0]), n3[0]) * 1000 +
          min(min(n1[1], n2[1]), n3[1]) * 100 +
          min(min(n1[2], n2[2]), n3[2]) * 10 + min(min(n1[3], n2[3]), n3[3]);
    return ans;
  }
};