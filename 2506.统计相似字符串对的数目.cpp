#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string findChar(string word) {
    string ans;
    unordered_map<char, int> memo;
    for (auto i : word) {
      memo[i] += 1;
    }
    for (auto i : memo) {
      ans += i.first;
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
  int similarPairs(vector<string> &words) {
    int ans = 0;
    for (int i = 0; i < words.size(); i++) {
      string s1 = findChar(words[i]);
      for (int j = i + 1; j <= words.size() - 1; j++) {
        string s2 = findChar(words[j]);
        if (s1 == s2) {
          ans++;
        }
      }
    }
    return ans;
  }
};