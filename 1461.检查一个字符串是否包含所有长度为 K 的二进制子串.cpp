#include<iostream>
#include <utility>
#include<vector>
#include<map>
#include<unordered_set>

class Solution {
public:
    bool hasAllCodes(std::string s, int k) {
        int len=s.length();
        int right=0;
        int left=0;
        std::unordered_set<std::string> cnt(len,0);
        int cnt_t=1<<k;
        for(right=0;right<len;right++){
            if(right-left+1==k){
                if(cnt.find(s.substr(left,k)) == cnt.end()){
                    cnt.insert(s.substr(left,k));
                }
                left++;
            }
        }
        return  cnt.size()==cnt_t;
    }
};