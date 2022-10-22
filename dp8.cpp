class Solution {
public:
    int getmin(int i, int j, vector<vector<int>> &dp, int x)
    {        
        if(i==0 and j==0) return x;
        int n = dp.size(), m = dp[0].size();
        
        if(i==0) return dp[i][j-1] + x;
        if(j==0) return dp[i-1][j] + x;
        return min(dp[i-1][j], dp[i][j-1]) + x;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        dp[0][0] = grid[0][0];
        
        for (int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                dp[i][j] = getmin(i,j, dp, grid[i][j]);
            }
        }
        return dp[n-1][m-1];
    }
};




















64. Minimum Path Sum
Medium

8852

116

Add to List

Share
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
