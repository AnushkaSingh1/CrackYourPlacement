class Solution {
public:
    struct Pos{
        int r, c;
        Pos(int rr, int cc) : r(rr), c(cc) {}
    };
    int swimInWater(vector<vector<int>>& grid) {
        auto cmp = [&](auto& p1, auto& p2) { return grid[p1.r][p1.c] > grid[p2.r][p2.c]; };
        priority_queue<Pos, vector<Pos>, decltype(cmp)> q(cmp);
        q.emplace(0, 0);
        int res = 0, n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        int dir[] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.top().r, c = q.top().c;
            q.pop();
            res = max(res, grid[r][c]);
            if (r == n - 1 && c == n - 1) return res;
            for (int i = 0, j = 1; i < 4; i++, j++) {
                int rr = r + dir[i], cc = c + dir[j];
                if (rr < 0 || cc < 0 || rr == n || cc == n || visited[rr][cc]) continue;
                visited[rr][cc] = true;
                q.emplace(rr, cc);
            }
        }
        return res;
    }
};














778. Swim in Rising Water
Hard
2.7K
178
Companies
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.
Accepted
108.2K
Submissions
181.2K
Acceptance Rate
59.7%
Seen this question in a real interview before?
1/4
Yes
No
Similar Questions
Related Topics
Copyright ©️ 2022 LeetCode All rights reserved


