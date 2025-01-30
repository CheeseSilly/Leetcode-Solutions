#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
  string reverseStr(string s, int k) {
    int n = s.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int flag = 0;
    string ans;
    string tmp;
    for (int i = 0; i < n; i++) {
      tmp += s[i];
      cnt1++;
      cnt2++;
      if (cnt2 == k) {
        reverse(tmp.begin(), tmp.end());
        ans += tmp;
        tmp.clear();
        cnt1 = 0;
        flag = 1;
      }
      if (cnt2 == 2 * k) {
        ans += tmp;
        tmp.clear();
        cnt2 = 0;
        cnt1 = 0;
        flag = 0;
      }
      cout << cnt1 << endl;
      cout << "cnt2 " << cnt2 << endl;
    }
    cout << cnt1;
    if (cnt1 < k && flag == 0) {
      reverse(tmp.begin(), tmp.end());
      ans += tmp;
    } else if (flag == 1) {
      ans += tmp;
    }
    return ans;
  }
};

class Solution2 {
public:
  string reverseStr(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i += k * 2) {
      // 0~k,2k~3k,.....
      reverse(s.begin() + i, s.begin() + min(i + k, n));
    }
    return s;
  }
};
