#include <iostream>
#include <vector>
#include <algorithm>

//给你一个整数数组 cuts ，其中 cuts[i] 表示你需要将棍子切开的位置。
//你可以按顺序完成切割，也可以根据需要更改切割的顺序。
//每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。
//对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。请参阅第一个示例以获得更直观的解释。
//返回切棍子的 最小总成本 。
class Solution {
public:
    int minCost(int n, std::vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        std::sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(m, 0));
        for (int len = 2; len < m; ++len) {
            for (int i = 0; i < m - len; ++i) {
                int j = i + len;
                dp[i][j] = INT32_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][m - 1];

    }
};


int main() {
    Solution solution;
    std::vector<int> cuts = {1, 3, 4, 5};
    int n = 7;
    std::cout << "Minimum cost to cut the stick: " << solution.minCost(n, cuts) << std::endl;
    return 0;
}