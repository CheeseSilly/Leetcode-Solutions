#include<bits/stdc++.h>

class Solution {
public:
int temp=0;
    int climbStairs(int n) {
       int dp[50];
       for(int i=0;i<50;i++){
        dp[i]=0;
       }
       dp[1]=1;
       dp[2]=2;
       if(n<3){
        return n;
       }
       else{
        if(dp[n]!=0){
            return dp[n];
        }
        for(int i=3;i<=n;i++){
           dp[i]=dp[i-1]+dp[i-2]; 
        }
       }
       return dp[n];
    }
};
