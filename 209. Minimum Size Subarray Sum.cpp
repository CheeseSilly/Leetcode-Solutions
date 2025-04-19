#include <climits>
#include <vector>
using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int ans=INT_MAX;
            int l=0;
            int sum=0;
            int flag=0;
            for(int r=0;r<nums.size();r++){
                sum+=nums[r];
                if(sum>=target){
                    ans=min(ans,r-l+1);
                    flag=1;
                }
                else{
                  sum-=nums[l++];  
                }
            }
            return flag==1?ans:0;
        }
    };



