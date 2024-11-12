#include<iostream>
#include<vector>

//给你一个 二进制 字符串 s 和一个整数 k。
//如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：
//字符串中 0 的数量最多为 k。
//字符串中 1 的数量最多为 k。
//返回一个整数，表示 s 的所有满足 k 约束 的
//子字符串
//的数量。

// class Solution {
// public:
//     int countKConstraintSubstrings(std::string s, int k) {
//         int res=0;
//         for(int i=0;i<s.size();i++){
//             for(int j=i;j<s.size();j++){
//                 int zero=0,one=0;
//                 for(int m=i;m<=j;m++){
//                     if(s[m]=='0'){
//                         zero++;
//                     }else{
//                         one++;
//                     }
//                     if(zero>k||one>k){
//                         break;
//                     }
//                     if(zero<=k||one<=k){
//                         res++;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };

//滑动窗口，枚举一个指针，求出符合的另一个指针
class Solution {
public:
    int countKConstraintSubstrings(std::string s, int k) {
        int res=0;
        int zero=0;
        int len=s.length();
        int right=0;
        int left=0;
        for(right=0;right<len;right++){
            if(s[right]=='0'){
                zero++;
            }
            while(zero>k&&right-left+1-zero>k){
                if(s[left]=='0'){
                    zero--;
                }
                left++;
            }
            res+=right-left+1;
        }
        return res;
    }
};