#include<iostream>
#include<vector>

class Solution {
public:
    int minFlips(std::vector<std::vector<int>>& grid) {
        int ans_r=0,ans_c=0;
        //row
        for(int i=0;i<grid.size();i++){
            for(int j1=0,j2=grid[0].size()-1;j1<j2;j1++,j2--){
                if(grid[i][j1]^grid[i][j2]){
                    ans_r++;
                }
            }
        }
        //col
        for(int j=0;j<grid[0].size();j++){
            for(int i1=0,i2=grid.size()-1;i1<i2;i1++,i2--){
                if(grid[i1][j]^grid[i2][j]){
                    ans_c++;
                }
            }
        }
        int ans=std::min(ans_r,ans_c);
        return ans;
    }
};