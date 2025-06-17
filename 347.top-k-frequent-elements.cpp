/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    std::unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }
    for (auto &[num, count] : freq) {
      pq.push({count, num});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    std::vector<int> result;
    while (!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
