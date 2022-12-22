#include <iostream>
#include <vector>
using std::vector;
class Solution{
public:
    // better off defining a "holder" subset as reference
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        helper(nums,res,0,nums.size()-1,subset);
        return res;

    }
private:
    void helper(const vector<int>& v,
                vector<vector<int>>& res, int start,int end,
                vector<int>& subset){
        if (start >end){
            res.push_back(subset);
            return;
        }
        subset.push_back(v[start]);
        helper(v,res,start+1,end,subset);
        subset.pop_back();
        helper (v,res,start+1,end,subset);
    }
};










78. Subsets
Medium
13K
184
Companies
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

