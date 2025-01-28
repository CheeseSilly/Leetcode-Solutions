#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> ans(arr1.size(), 0);
    int move = 0;
    sort(arr1.begin(), arr1.end());
    map<int, int> counter;
    for (auto i : arr1) {
      counter[i]++;
    }
    for (auto i : arr2) {
      while (counter[i]-- > 0) {
        ans[move] = i;
        move++;
      }
    }
    int move1 = move;
    for (auto [i, j] : counter) {
      while (j-- > 0) {
        ans[move] = i;
        move++;
      }
    }
    return ans;
  }
};

class Solution2 {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> ans(arr1.size(), 0);
    int move = 0;
    sort(arr1.begin(), arr1.end());
    vector<int> counter(1001, 0);
    for (auto i : arr1) {
      counter[i]++;
    }
    for (auto i : arr2) {
      while (counter[i]-- > 0) {
        ans[move] = i;
        move++;
      }
    }
    int move1 = move;
    for (int i = 0; i < counter.size(); i++) {
      while (counter[i]-- > 0) {
        ans[move] = i;
        move++;
      }
    }
    return ans;
  }
};