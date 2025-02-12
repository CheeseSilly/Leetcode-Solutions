#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int trans(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
  int ans = 0;
  int countBalls(int lowLimit, int highLimit) {
    int n = highLimit - lowLimit + 1;
    unordered_map<int, int> boxes;
    int sum = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
      boxes[trans(i)] += 1;
    }
    for (auto i : boxes) {
      if (i.second > sum) {
        sum = i.second;
      }
    }
    return sum;
  }
};