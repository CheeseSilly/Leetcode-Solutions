#include<iostream>
#include<vector>
class Solution {
public:
    int rob(std::vector<int>& nums) {
        int res=0;
        int len=nums.size();
        std::vector<int> dp(len,-1);
        dp[0]=nums[0];
        dp[1]=nums[1];
        if(len<3){
            res=std::max(nums[0],nums[1]);
        }
        for(int i=3;i<len;i++){
            if(dp[i]!=-1){
                return dp[i];
            }
            res=std::max(dp[i-1],dp[i-2]+nums[i]);
            dp[i]=res;
        }
        return res;
    }
};