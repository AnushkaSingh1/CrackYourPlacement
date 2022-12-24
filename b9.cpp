vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> result;
    vector<int> column(n, 0);
    
    dfs(result, column, n, 0);
    return result;
}

void dfs(vector<vector<string>>& result, vector<int>& column, int n, int ROW)
{
    if (ROW == n) // result
    {
        vector<string> solution;
        for (int row = 0; row < n; row++)
        {
            string line;
            for (int col = 0; col < n; col++)
                line.push_back(column[row] == col ? 'Q' : '.');
            solution.push_back(line);        
        }
        result.push_back(solution);
        return;
    }
    
    for (int col = 0; col < n; col++)
    {
        column[ROW] = col;
        if (isValid(column, ROW))
            dfs(result, column, n, ROW + 1);
    }
}

bool isValid(vector<int> column, int ROW)
{
    for (int i = 0; i < ROW; i++)
        if (column[i] == column[ROW] || abs(column[i] - column[ROW]) == (ROW - i))
            return false;
    return true;
}



















51. N-Queens
Hard
9K
199
Companies
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9

