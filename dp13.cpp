class Solution {
public: 
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxi = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    dp[i][j] = 1 + min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
                    maxi = max(maxi,dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxi*maxi;
    }
};















221. Maximal Square
Medium

8181

176

Add to List

Share
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
