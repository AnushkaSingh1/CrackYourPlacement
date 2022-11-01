class Solution {

    void solve(int ind,int target,vector<int>& ar,vector<int>& temp,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<ar.size();i++){
            if(i>ind && ar[i]==ar[i-1]) continue;
            if(ar[i]>target) break;
            temp.push_back(ar[i]);
            solve(i+1,target-ar[i],ar,temp,ans);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0,target,candidates,temp,ans);
        return ans;
    }
};















40. Combination Sum II
Medium

7197

176

Add to List

Share
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
