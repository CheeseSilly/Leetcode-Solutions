#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    unordered_map<int, int> um1_2;
    unordered_map<int, int> um3_4;
    int res = 0;
    int n = nums1.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        um1_2[nums1[i] + nums2[j]]++;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        um3_4[nums3[i] + nums4[j]]++;
      }
    }

    for (auto i : um1_2) {
      if (um3_4.contains(0 - i.first)) {
        res += um3_4[0 - i.first] * i.second;
      }
    }
    return res;
  }
};