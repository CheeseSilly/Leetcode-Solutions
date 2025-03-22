#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
    vector<int> ans;
    //(row,count)
    unordered_map<int, int> um;
    // check all 0's case
    int flag = 0;
    int r = 0;
    for (auto &i : mat) {
      for (auto &j : i) {
        if (j == 1) {
          um[r]++;
          flag = 1;
        }
      }
      r++;
    }

    if (flag == 0) {
      ans = {0, 0};
      return ans;
    }

    int count = 0;

    for (auto &i : um) {
      if (i.second > count) {
        count = max(count, i.second);
        r = i.first;
      }
      if (i.second == count) {
        r = min(r, i.first);
      }
    }

    ans.push_back(r);
    ans.push_back(count);
    return ans;
  }
};
