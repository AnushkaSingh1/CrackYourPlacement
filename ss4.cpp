class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        
        int l = *max_element(arr.begin(),arr.end());
        int r = accumulate(arr.begin(),arr.end(),0);
        
        while(l < r){
            int m = (l + r) >> 1;
            int split = 1;
            int current = 0;
            
            for(int i = 0; i<arr.size() ; i++){
                
                if(current + arr[i] > m){
                    current = 0;
                    split++;
                }
                current += arr[i];
            }
            
            if(split > k) l = m + 1;
            else r = m;
        }
        
        return l ;
    }
};



















410. Split Array Largest Sum
Hard

7173

163

Add to List

Share
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)



