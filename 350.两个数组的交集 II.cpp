#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans(0);
    unordered_map<int, int> dic1;
    unordered_map<int, int> dic2;
    for (int i = 0; i < nums1.size(); i++) {
      dic1[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); i++) {
      if (dic1.find(nums2[i]) != dic1.end()) {
        dic2[nums2[i]]++;
      }
    }
    for (auto i : dic1) {
      int tmp = i.first;
      if (dic2[tmp] > 0) {
        if (dic2[tmp] < i.second) {
          for (int i = 0; i < dic2[tmp]; i++) {
            ans.push_back(tmp);
          }
        } else {
          for (int j = 0; j < i.second; j++) {
            ans.push_back(tmp);
          }
        }
      }
    }
    return ans;
  }
};