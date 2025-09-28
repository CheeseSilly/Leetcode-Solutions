#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> res;
  std::vector<std::vector<int>> allPathsSourceTarget(
      std::vector<std::vector<int>> &graph) {
    int n = graph.size();
    std::vector<int> pass;
    pass.push_back(0);
    dfs(graph, pass, 0, n);
    return res;
  }

 private:
  void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &pass, int i,
           int n) {
    if (i == n - 1) {
      res.push_back(pass);
      return;
    } else {
      for (int t = 0; t < graph[i].size(); t++) {
        pass.push_back(graph[i][t]);
        dfs(graph, pass, graph[i][t], n);
        pass.pop_back();
      }
    }
  }
};
