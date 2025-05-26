#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
  string reverseStr(string s, int k) {
    int n = s.size();
    for (int i = 0; i < s.size(); i += 2 * k) {
      reverse(s.begin() + i, s.begin() + min(i + k, n));
    }
    return s;
  }
};