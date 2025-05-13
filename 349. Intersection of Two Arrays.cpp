#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> um1;
    unordered_map<int, int> um2;

    for (auto i : nums1) {
      um1[i]++;
    }

    for (auto i : nums2) {
      um2[i]++;
    }

    vector<int> res;
    unordered_map<int, int> um3;

    for (auto i : um1) {
      if (um2.contains(i.first)) {
        if (i.second > 1 || um2[i.first] > 1) {
          if (!um3.contains(i.first)) {
            res.push_back(i.first);
            um3[i.first]++;
          }
        } else {
          res.push_back(i.first);
        }
      }
    }
    return res;
  }
};