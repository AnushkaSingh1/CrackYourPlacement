class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ad) {
        map<int,vector<int>> m;
        map<int,bool> vis;
        vector<int> ans;
        for(auto t:ad)
        {
            m[t[0]].push_back((t[1]));
            m[t[1]].push_back((t[0]));
            vis[t[0]]=false;
            vis[t[1]]=false;
        }
        for(auto t: m)
        {
            if(!vis[t.first] && (t.second).size()==1)
            {
                int a=t.first;
                queue <int> q;
                q.push(a);
                while(!q.empty())
                {
                    int k=q.front();
                    q.pop();
                    ans.push_back(k);
                    vis[k]=true;
                    for(auto i : m[k])
                        if(!vis[i])
                            q.push(i);
                }
            }
        }
        return ans;
    }
};



















1743. Restore the Array From Adjacent Pairs
Medium

724

12

Add to List

Share
There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.

 

Example 1:

Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
Example 2:

Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
Example 3:

Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]
 

Constraints:

nums.length == n
adjacentPairs.length == n - 1
adjacentPairs[i].length == 2
2 <= n <= 105
-105 <= nums[i], ui, vi <= 105
There exists some nums that has adjacentPairs as its pairs.






