#include <cstddef>
#include <cstdio>
#include<iostream>

class Solution {
public:
    int maxVowels(std::string s, int k) {
        int len=s.length();
        int ans=0;
        int max=0;
        int left=0;
        for(int right=0;right<len;right++){
            if(s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='o'||s[right]=='u'){
                max++;
            }
            if(right-left+1>k){  
                if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u'){
                    max--;
                }
                left++;
            }
            ans=std::max(ans,max);
        }
        return ans;
    }
};
