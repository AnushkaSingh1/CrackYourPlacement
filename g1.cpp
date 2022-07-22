static bool isValid(int i, int j, int r, int c) { return (i >= 0 && i < r && j >= 0 && j < c); }
int numIslands(vector <vector<char>> &v) {
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, 1, -1, 0};
    int rows = v.size();
    int cols = v[0].size();
    vector<vector<bool>>vis(rows,vector<bool>(cols,false));
    int ans = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (v[i][j] == '1') {
                if (!vis[i][j]) {
                    ++ans;
                    queue <pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int,int> p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int r = p.first + dx[k]; // new row
                            int c = p.second + dy[k]; // new col
                            if (isValid(r, c, rows, cols) && !vis[r][c] && v[r][c] == '1') {
                                q.push({r, c});
                                vis[r][c] = true;
                            }
                        }

                    }
                }
            }
        }
    }
    return ans;
}























static bool isValid(int i, int j, int r, int c) { return (i >= 0 && i < r && j >= 0 && j < c); }

void dfs(int i, int j, int r, int c, vector <vector<char>> &grid) {
    if (!isValid(i, j, r, c) || grid[i][j] != '1')return; // base case
    grid[i][j] = 2; //visited 
    dfs(i + 1, j, r, c, grid);
    dfs(i, j + 1, r, c, grid);
    dfs(i, j - 1, r, c, grid);
    dfs(i - 1, j, r, c, grid);
}

int numIslands(vector <vector<char>> &v) {
    int rows = v.size();
    int cols = v[0].size();
    int ans = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (v[i][j] == '1') {
                ++ans;
                dfs(i, j, rows, cols, v);
            }
        }
    }
    return ans;
}






















Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
