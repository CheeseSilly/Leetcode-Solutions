#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>

class Solution {
public:
    long long maxSum(std::vector<int>& nums, int m, int k) {
        int len = nums.size();
        int right=0;
        int left=0;
        long long ans=0;
        long long sum=0;
        int count=0;
        int count_b=0;
        std::unordered_map<int,int> hash;
        for(right=0;right<len;right++){
            sum+=nums[right]; 
            hash[nums[right]]++;
            if(right-left+1==k){
                if(hash.size()>=m){   
                    ans=std::max(ans,sum);
                }  
                sum-=nums[left];
                if(--hash[nums[left]]==0){
                    hash.erase(nums[left]);
                }
                left++;
            }
        }
        return ans;

    }
};