#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  vector<int> mergesort(vector<int> left, vector<int> right) {
    vector<int> result;
    auto it1 = left.begin();
    auto it2 = right.begin();

    while (it1 != left.end() && it2 != right.end()) {
      if (*it1 <= *it2) {
        result.push_back(*it1);
        ++it1;
      } else {
        result.push_back(*it2);
        ++it2;
      }
    }

    // 剩余元素
    while (it1 != left.end()) {
      result.push_back(*it1);
      ++it1;
    }

    while (it2 != right.end()) {
      result.push_back(*it2);
      ++it2;
    }

    return result;
  }
  vector<int> merge(vector<int> nums) {
    if (nums.size() <= 1) {
      return nums;
    }

    auto mid = nums.begin() + nums.size() / 2;
    vector<int> left(nums.begin(), mid);
    vector<int> right(mid, nums.end());

    left = merge(left);
    right = merge(right);

    return mergesort(left, right);
  }

public:
  vector<int> sortArray(vector<int> &nums) { return merge(nums); }
};