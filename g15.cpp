class Solution {
public:
		vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
		int largestIsland(vector<vector<int>>& grid) {
				int m = grid.size();
				int n = grid[0].size();
				vector<vector<bool>> check(m, vector<bool>(n, false));
				unordered_map<int, int> parents;
				unordered_map<int, int> count;//for each ultimate node, the area
				vector<pair<int,int>> zeros;
				int res = 0;

				//id: i*n + j
				for(int i = 0; i < m; ++i){
						for(int j = 0; j < n; ++j){
								if(check[i][j]) continue;
								if(!grid[i][j]){
										zeros.push_back({i, j});
										continue;
								}
								count[i*n+j] = 0;
								dfs(grid, check, i, j, m, n, i*n + j, parents, count);
								res = max(res, count[i*n+j]);
						}
				}
			
				for(auto p : zeros){
						int i = p.first, j = p.second;
						unordered_set<int> st;
						for(auto d : dir){
								int ii = i + d.first;
								int jj = j + d.second;
								if(ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj]){
										st.insert(parents[ii*n+jj]);
								}
						}
						int temp = 0;
						for(auto s : st) temp += count[s];
						res = max(res, temp + 1);
				}
				return res;
		}

		void dfs(vector<vector<int>>& grid, vector<vector<bool>>& check, int i, int j, int m, int n, int par, unordered_map<int,int>& parents, unordered_map<int,int>& count){
				check[i][j] = true;
				parents[i*n + j] = par;
				count[par]++;
				for(auto d : dir){
						int ii = i + d.first;
						int jj = j + d.second;
						if(ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] && !check[ii][jj]){
								dfs(grid, check, ii, jj, m, n, par, parents, count);
						}
				}
				return;
		}
};












827. Making A Large Island
Hard
2.8K
56
Companies
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.















