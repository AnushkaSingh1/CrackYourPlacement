class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int total = row*col;
        
        int startrow = 0;
        int startcol = 0;
        int endrow = row - 1;
        int endcol = col - 1;
        
        while(count < total){
            //starting row
            for(int i=startcol;count < total && i<=endcol; i++){
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            
            //ending col
            for(int i=startrow;count < total && i<=endrow; i++){
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            
            //ending row
            for(int i=endcol;count < total && i>=startcol; i--){
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
            
            //start col
            for(int i=endrow;count < total && i>=startrow; i--){
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};













54. Spiral Matrix
Medium

8471

893

Add to List

Share
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
