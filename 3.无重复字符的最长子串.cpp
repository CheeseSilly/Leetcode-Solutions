#include<iostream>
#include<vector>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.size();
        int ans = 0;
        std::vector<int> index(128, -1);
        //i为左指针，j为右指针，i和j之间的子串为无重复字符的子串。
        //当遇到重复字符，左指针会移动到重复字符的下一个位置，之后ans不变，更新重复字符的最新位置。
        //若无重复字符，i则不变，ans更新为当前子串的长度。
        for (int j = 0, i = 0; j < n; j++) {
            i = std::max(index[s[j]] + 1, i);
            ans = std::max(ans, j - i + 1);
            index[s[j]] = j;
        }
        return ans;
    }
};

int main() {
    std::string s = "abcabcbb";
    Solution solution;
    int result = solution.lengthOfLongestSubstring(s);
    std::cout << result << std::endl;
    return 0;
}