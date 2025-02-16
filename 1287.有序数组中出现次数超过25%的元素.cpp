#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// hash
class Solution1 {
public:
  int findSpecialInteger(vector<int> &arr) {
    int n = arr.size();
    int idx = n / 4;
    int ans = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[arr[i]]++;
    }
    for (auto i : cnt) {
      if (i.second > idx) {
        ans = i.first;
      }
    }
    return ans;
  }
};

class Solution2 {
public:
  int findSpecialInteger(vector<int> &arr) {
    int n = arr.size();
    int m = n / 4;
    for (int i : {m, m * 2 + 1}) {
      int x = arr[i];
      if (ranges::upper_bound(arr, x) - ranges::lower_bound(arr, x) > m) {
        return x;
      }
    }
    // 如果答案不是 arr[m] 也不是 arr[2m+1]，那么答案一定是 arr[3m+2]
    return arr[m * 3 + 2];
  }
};

class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    int n = arr.size();
    int m = n / 4;
    for (int i = 0; i < n - m; i++) {
      if (arr[i] == arr[i + m]) {
        return arr[i];
      }
    }
    return arr[0];
  }
};