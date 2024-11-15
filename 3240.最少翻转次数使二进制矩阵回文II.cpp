#include<iostream>
#include<vector>

class Solution {
public:
    int minFlips(std::vector<std::vector<int>>& grid) {
        auto n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<m/2;j++){
                int sum=grid[i][j]+grid[i][m-1-j]+grid[n-1-i][j]+grid[n-1-i][m-j-1];
                ans+=std::min(sum,4-sum);
            }
        }
        //如果同为奇数，则中间必为0
        if(m%2&&n%2){
            ans+=grid[n/2][m/2];
        }
        int diff = 0, cnt1 = 0;
        if (n % 2) {
            // 统计正中间这一排
            for (int j = 0; j < m / 2; j++) {
                if (grid[n/ 2][j] != grid[n / 2][m - 1 - j]) {
                    diff++;
                } else {
                    cnt1 += grid[n / 2][j] * 2;
                }
            }
        }
        if (m % 2) {
            // 统计正中间这一列
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][m / 2] != grid[n - 1 - i][m / 2]) {
                    diff++;
                } else {
                    cnt1 += grid[i][m / 2] * 2;
                }
            }
        }

        return ans + (diff ? diff : cnt1 % 4);


    }
};