#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
    vector<int> sum(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++) {
      sum[i + 1] = sum[i] + (nums[i] % modulo == k);
    }

    //(sum[j+1]-sum[i])%modulo==k%modulo
    //(sum[j+1]-k)%modulo=sum[j]%modulo
    unordered_map<int, int> um;
    long long ans = 0;
    for (auto s : sum) {
      if (s - k >= 0) {
        ans += um[(s - k) % modulo];
      }
      um[s % modulo]++;
    }
    return ans;
  }
};