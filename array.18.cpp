class Solution {
public:
    int visited[6][6]={0};
    bool dfs(int r, int c, int idx, int m, int n,vector<vector<char>>& board, string word){
        if(idx == word.size()){return true;}
        if (r<0 || r>=m || c<0 || c>=n || board[r][c]!=word[idx] || visited[r][c] == 1){
                return false;}
        visited[r][c] = 1;
        bool res = dfs(r+1,c,idx+1,m,n,board,word) ||  dfs(r,c+1,idx+1,m,n,board,word) ||  dfs(r-1,c,idx+1,m,n,board,word) ||  dfs(r,c-1,idx+1,m,n,board,word);
        visited[r][c] = 0;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (dfs(i,j,0,m,n,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};














79. Word Search
Medium

10546

393

Add to List

Share
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
