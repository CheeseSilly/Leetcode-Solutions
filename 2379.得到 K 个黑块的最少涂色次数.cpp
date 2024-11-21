#include<iostream>
#include<climits>

class Solution {
public:
    int minimumRecolors(std::string blocks, int k) {
        int len=blocks.length();
        int right=0;
        int left=0;
        int ans=INT_MAX;
        int min=0;
        int cnt_W=0;
        int cnt_B=0;
        for(right=0;right<len;right++){
            if(blocks[right]=='W'){
                cnt_W++;
            }
            if(right-left+1==k){
                min=cnt_W;
                ans=std::min(ans,min);
                if(blocks[left]=='W'){
                    cnt_W--;
                }
                left++;
            }
        }
        return ans;
    }
};