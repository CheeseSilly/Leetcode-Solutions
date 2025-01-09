#include <iostream>
using namespace std;

class Solution {
  bool isValid(int *word2Cnt, int *tmpCnt) {
    for (int i = 0; i < 26; i++) {
      if (word2Cnt[i] > tmpCnt[i]) {
        return false;
      }
    }

    return true;
  }

public:
  long long validSubstringCount(string word1, string word2) {
    long long ans = 0;
    int word2Cnt[26]{};
    for (char c : word2) {
      word2Cnt[c - 'a']++;
    }

    int tmpCnt[26]{};
    int left = 0;
    for (int right = 0; right < word1.length(); right++) {
      char curChar = word1[right];
      tmpCnt[curChar - 'a']++;
      while (isValid(word2Cnt, tmpCnt)) {
        tmpCnt[word1[left] - 'a']--;
        left++;
      }

      ans += left;
    }

    return ans;
  }
};