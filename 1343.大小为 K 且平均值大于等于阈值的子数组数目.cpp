#include<iostream>
#include<vector>

class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
        int len=arr.size();
        int right=0;
        int left=0;
        int ans=0;
        int max=0;
        for(right=0;right<len;right++){
            max+=arr[right];
            if(right-left+1==k){
                if(max/k>=threshold){
                    ans++;
                }
                max-=arr[left];
                left++;
            }
        }
        return ans;
    }
};