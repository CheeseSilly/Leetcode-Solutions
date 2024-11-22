#include<iostream>
#include<vector>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int right=0;
        int ans=0;
        int max=0;
        int cnt_1=0;
        int left=0;
        int add=0;
        for(right=0;right<n;right++){
            if(grumpy[right]==0){
                max+=customers[right];
            }else{
                cnt_1+=customers[right];
            }
            if(right-left+1==minutes){
                add=std::max(add,cnt_1);
                ans=std::max(ans,max+add);
                if(grumpy[left]==1){
                    cnt_1-=customers[left];
                }
                left++;
            }
        }
        return ans;
    }
};