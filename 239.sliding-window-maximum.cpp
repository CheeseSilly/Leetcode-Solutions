/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <deque>
#include <vector>
class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    int left = 0;
    std::vector<int> ans;
    int maxNum = 0;
    int preNum = 0;
    for (int right = 0; right < nums.size(); right++) {
      // compare nums[right] with qe.back().
      // if qe.back()< nums[right]
      // update deque.
      while (!qe.empty() && qe.back() < nums[right]) {
        qe.pop_back();
      }
      qe.push_back(nums[right]);
      if (right - left + 1 > k) {
        preNum = nums[left];
        // if nums[left] is just the max,then remove it.
        // update deque,and compare next num using current deque.
        if (!qe.empty() && qe.front() == nums[left])
          qe.pop_front();
        left++;
      }
      if (right - left + 1 == k) {
        {
          /*   maxNum = *std::ranges::max_element(nums.begin() + left,
                                                nums.begin() + right + 1);

             ans.push_back(maxNum);
                                        */
          maxNum = qe.front();
          ans.push_back(maxNum);
        }
      }
    }
    return ans;
  }

private:
  std::deque<int> qe;
};
// @lc code=end
