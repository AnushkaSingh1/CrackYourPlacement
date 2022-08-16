class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, ll target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        ll n = nums.size();
        for(ll i=0; i<n-3; i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            
            for(ll j=i+1; j<n-2; j++) {
                if(j>i+1 && nums[j]==nums[j-1]) {
                continue;
                }
                
                ll tSum = target - (nums[i]+nums[j]);
                ll l = j+1;
                ll h = n-1;
                
                while(l<h) {
                    if(nums[l] + nums[h] == tSum) {
                        vector<int>oneAns = {nums[i], nums[j], nums[l], nums[h]};
                        ans.push_back(oneAns);
                        
                        while(l<h && nums[l]==nums[l+1]) {
                            l++;
                        }
                        
                        while(l<h && nums[h]==nums[h-1]) {
                            h--;
                        }
                        
                        l++;
                        h--;
                    }
                    
                    else if(nums[l] + nums[h]<tSum) {
                        l++;
                    }
                    
                    else {
                        h--;
                    }
                }
            }
        }
        return ans;
    }
};















18. 4Sum
Medium

7254

845

Add to List

Share
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109







