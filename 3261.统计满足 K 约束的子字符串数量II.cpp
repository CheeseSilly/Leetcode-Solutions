#include<iostream>
#include<vector>

//给你一个 二进制 字符串 s 和一个整数 k。
// 另给你一个二维整数数组 queries ，其中 queries[i] = [li, ri] 。
// 如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：
// 字符串中 0 的数量最多为 k。
// 字符串中 1 的数量最多为 k。
// 返回一个整数数组 answer ，其中 answer[i] 表示 s[li..ri] 中满足 k 约束 的 
// 子字符串
//  的数量。

//滑动窗口+二分查找+前缀和
class Solution {
public:
    std::vector<long long> countKConstraintSubstrings(std::string s, int k, std::vector<std::vector<int>>& queries) {
        int n = s.length();
        std::vector<int> left(n);
        std::vector<long long> sum(n + 1);
        int cnt[2]{}, l = 0;
        for (int i = 0; i < n; i++) {
            cnt[s[i] & 1]++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l++] & 1]--;
            }
            left[i] = l; // 记录合法子串右端点 i 对应的最小左端点 l
            // 计算 i-left[i]+1 的前缀和
            sum[i + 1] = sum[i] + i - l + 1;
        }

        std::vector<long long> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            // 如果区间内所有数都小于 l，结果是 j=r+1
            int j = lower_bound(left.begin() + l, left.begin() + r + 1, l) - left.begin();
            ans[i] = sum[r + 1] - sum[j] + (long long) (j - l + 1) * (j - l) / 2;
        }
        return ans;
    }
    
};