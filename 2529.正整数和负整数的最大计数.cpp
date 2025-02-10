#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumCount(vector<int> &nums) {
    int n = nums.size();
    int l = 0;
    int r = nums.size() - 1;
    int ans = 0;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      // nums[mid]<=0,[mid+1,r]
      if (nums[mid] < 0) {
        l = mid + 1;
      } else if (nums[mid] >= 0) { // nums[mid]>=0,[l,mid-1]
        r = mid - 1;
      }
    }
    int neg = l;
    cout << neg << endl;
    l = 0, r = n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      // nums[mid]<=0,[mid+1,r]
      if (nums[mid] <= 0) {
        l = mid + 1;
      } else if (nums[mid] > 0) { // nums[mid]>=0,[l,mid-1]
        r = mid - 1;
      }
    }
    int pos = n - 1 - r;
    cout << pos;
    // [l,n-1]:>0
    // [0,r]:<0
    // for(auto i:nums){
    //     if(i!=0){
    //         flag=0;
    //         break;
    //     }else{
    //         flag=1;
    //     }
    // }
    ans = max(neg, pos);
    return ans;
  }
};