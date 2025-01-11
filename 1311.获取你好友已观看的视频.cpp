#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos,
                                        vector<vector<int>> &friends, int id,
                                        int targetLevel) {
    int N = friends.size();
    unordered_map<string, int> mp;
    queue<int> q{{id}};
    vector<int> visited(N, false);
    int level = 0;
    while (!q.empty()) {
      auto size = q.size();
      while (size--) {
        auto cur = q.front();
        q.pop();
        if (visited[cur]) {
          continue;
        }
        visited[cur] = true;

        if (level == targetLevel) {
          for (const auto &video : watchedVideos[cur]) {
            mp[video]++;
          }
        }
        for (const auto &f : friends[cur]) {
          q.push(f);
        }
      }
      level++;
    }

    vector<pair<string, int>> freq;
    for (const auto &m : mp) {
      freq.emplace_back(make_pair(m.first, m.second));
    }
    auto cmp = [](const auto &a, const auto &b) {
      return a.second < b.second || (a.second == b.second && a < b);
    };
    sort(freq.begin(), freq.end(), cmp);

    vector<string> res;
    for (const auto &f : freq) {
      res.emplace_back(f.first);
    }

    return res;
  }
};