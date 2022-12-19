class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        auto getMaxHistogram = [](const vector<int> &v)->int{
            vector<int> q;
            int ans = 0;
            for(int i = 0; i <= v.size(); ++i){
                while(!q.empty() && (i == v.size() || v[i] <= v[q.back()])){
                    int top = q.back();
                    q.pop_back();
                    ans = max(ans,(i - (q.empty() ? 0 : (q.back() + 1)))*v[top]);
                }
                
                if(i != v.size()){
                    q.push_back(i);
                }
            }
            
            return ans;
        };
        
        int ans = 0;
        
        if(matrix.empty()){
            return ans;
        }
        
        vector<int> temp(matrix[0].size(),0);
       
        for(auto &v : matrix){
            
           for(int i = 0; i < temp.size(); ++i){
              if(v[i] - '0' == 0){
                  temp[i] = 0;
              }
              else{
                  temp[i]++;
              }
           }
        
           ans = max(ans,getMaxHistogram(temp));
        }
        
        return ans;
    }
};



















85. Maximal Rectangle
Hard
8K
128
Companies
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
