class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int res=0;
        int n=nums.size();
        unordered_map<int, int>mapp;
        for(int i=0;i<n;i++)
            mapp[nums[i]]++;
        for(int i=0;i<n;i++)
        {
            if(mapp[nums[i]]>(n/2))
                res= nums[i];
        }
        return res;  
    }
};









169. Majority Element
Easy

11435

373

Add to List

Share
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109










