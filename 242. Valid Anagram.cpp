#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> s_c;
    unordered_map<char, int> t_c;

    for (auto i : s) {
      s_c[i]++;
    }
    for (auto i : t) {
      t_c[i]++;
    }

    if (s_c == t_c) {
      return true;
    } else {
      return false;
    }
  }
};