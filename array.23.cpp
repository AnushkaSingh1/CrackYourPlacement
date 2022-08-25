class Solution {
public:
    bool isvalid(int x,int y,vector<vector<int>>& board){
        return (x>=0&&x<board.size()&&y>=0&&y<board[0].size());
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<int>x={0,0,1,1,1,-1,-1,-1};
        vector<int>y={1,-1,1,-1,0,0,1,-1};
        int n=board.size();
        int m=board[0].size();
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                int count=0;
                for(int i=0;i<8;i++){
                    int curr_x=row+x[i],curr_y=col+y[i];
                    if(isvalid(curr_x,curr_y,board)&&abs(board[curr_x][curr_y])==1){
                        count++;
                    }
                    
                }
                if(abs(board[row][col])==1&&(count<2||count>3)) {board[row][col]=-1;}
                if(abs(board[row][col])==0&&count==3){board[row][col]=2;}
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]>=1)
                    board[i][j]=1;
                else
                    board[i][j]=0;
        }
        
    }
    }
};



















289. Game of Life
Medium

5066

454

Add to List

Share
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
 

Follow up:

Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?







