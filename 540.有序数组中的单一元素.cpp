#include<iostream>
#include<vector>
class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int res=0;
        if(nums.size()==1) {
            return nums[0];
        }
        for(auto i: nums) {
            res^=i;
        }
        return res;
    }
};