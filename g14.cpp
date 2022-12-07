class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = (h ? matrix[0].size():0);
        vector<vector<int>> dp(h, vector<int> (w, 0));
        int maxlen = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                maxlen = max(maxlen, dfsSearch(matrix, dp, INT_MIN, i, j));
        return maxlen;
    }
    int dfsSearch(vector<vector<int>> &mat, vector<vector<int>> &dp, int prev, int i, int j) {
        int h = mat.size(), w = mat[0].size();
        if (prev >= mat[i][j]) return 0;
        if (dp[i][j])  return dp[i][j];
        
        int val = mat[i][j];
        int d[4] = {
            i ? dfsSearch(mat, dp, val, i-1, j):0,
            i+1 < h ? dfsSearch(mat, dp, val, i+1, j):0,
            j ? dfsSearch(mat, dp, val, i, j-1):0,
            j+1 < w ? dfsSearch(mat, dp, val, i, j+1):0
        };
        return dp[i][j] = max(d[0], max(d[1], max(d[2], d[3]))) + 1;
    }
};




















329. Longest Increasing Path in a Matrix
Hard
7.5K
111
Companies
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
Accepted
420.8K
Submissions
805.2K
Acceptance Rate
52.3%
Seen this question in a real interview before?
1/4
Yes
No
Similar Questions

