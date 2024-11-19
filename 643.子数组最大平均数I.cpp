#include <cstdint>
#include <climits>
#include<iostream>
#include<vector>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         auto len=nums.size();
        size_t right=0;
        size_t left=0;
        int ans=INT_MIN;
        int max=0;
        for(right=0;right<len;right++){
            max+=nums[right];
            if(right-left+1==k){
                ans=std::max(ans,max);
                max-=nums[left];
                left++;
            }
        }
        return static_cast<double>(ans)/k;
    }
};