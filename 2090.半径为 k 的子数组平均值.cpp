#include <cstddef>
#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        int n=nums.size();
        std::vector<int> avgs(n,-1);
        int right=0;
        size_t sum=0;
        for(right=0;right<n;right++){
            sum+=nums[right];
            if(right>=2*k+1){
                avgs[right-k]=(sum)/(2*k+1);
                sum-=nums[right-2*k];
            }
        }
        return avgs;

    }
};