#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>

using namespace std;

/*
 Overflow Error
*/
// class Solution {
// public:
//   int rec(vector<int> &nums, int k, int ans) {
//     sort(nums.rbegin(), nums.rend());
//     if (nums[-1] >= k) {
//       return ans;
//     }
//     int a = nums[-1], b = nums[-2];
//     nums.pop_back();
//     nums.pop_back();
//     nums.push_back(min(a, b) * 2 + max(a, b));
//     return rec(nums, k, ans + 1);
//   }
//   int minOperations(vector<int> &nums, int k) {
//     int n = nums.size();
//     int ans = 0;
//     if (n < 2) {
//       return 0;
//     }
//     return rec(nums, k, ans);
//   }
// };

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    priority_queue<long long, vector<long long>, greater<>> pq;
    for (auto i : nums) {
      pq.push(i);
    }
    int ans = 0;
    while (pq.top() < k) {
      auto a = pq.top();
      pq.pop();
      auto b = pq.top();
      pq.pop();
      pq.push(min(a, b) * 2 + max(a, b));
      ans++;
    }
    return ans;
  }
};
