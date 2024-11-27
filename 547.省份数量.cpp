#include <iostream>
#include <vector>

class Solution {
private:
  void dfs(int i, std::vector<std::vector<int>> &isConnected,
           std::vector<bool> &visited) {
    int n = isConnected.size();
    visited[i] = 0;
    for (int j = 0; j < n; j++) {
      if (isConnected[i][j] && !visited[j]) {
        dfs(j, isConnected, visited);
      }
    }
  }

public:
  int findCircleNum(std::vector<std::vector<int>> &isConnected) {
    int n = isConnected.size();
    std::vector<bool> visited(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (visited[i])
        continue;
      dfs(i, isConnected, visited);
      ans += 1;
    }
    return ans;
  }
};