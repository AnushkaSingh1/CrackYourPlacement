int dfs(vector<vector<int>>& g, int i, int j, int s, int t_s) {
  if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1) return 0;
  if (g[i][j] == 2) return s == t_s ? 1 : 0;
  g[i][j] = -1;
  int paths = dfs(g, i + 1, j, s + 1, t_s) + dfs(g, i - 1, j, s + 1, t_s) +
    dfs(g, i, j + 1, s + 1, t_s) + dfs(g, i, j - 1, s + 1, t_s);
  g[i][j] = 0;
  return paths;
}
int uniquePathsIII(vector<vector<int>>& g) {
  auto i1 = 0, j1 = 0, t_steps = 0;
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[0].size(); ++j) {
      if (g[i][j] == 1) i1 = i, j1 = j;
      if (g[i][j] != -1) ++t_steps;
    }
  return dfs(g, i1, j1, 1, t_steps);
}













980. Unique Paths III
Hard
3.5K
149
Companies
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:


Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.
