class Solution {
public:
    
    vector<int> res;
    
    vector<int> count_node;
    
    void dfs_count(vector<vector<int>>& adj, int u, int parent)
    {
        for(auto v : adj[u])
        {
            if(v == parent)
                continue;
            
            dfs_count(adj, v, u);
            
            count_node[u] += count_node[v];
            
            res[u] += res[v] + count_node[v];
        }
        
        count_node[u]++;
    }
    
    void dfs_final(vector<vector<int>>& adj, int u, int parent)
    {
        for(auto v : adj[u])
        {
            if(v == parent)
            {
                continue;
            }
            
            res[v] = res[u] - count_node[v] + (adj.size() - count_node[v]);
            
            dfs_final(adj, v, u);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        res.resize(n, 0);
        
        count_node.resize(n, 0);
        
        // create adjacency list
        
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            
            int v = edges[i][1];
            
            adj[u].push_back(v);
            
            adj[v].push_back(u);
        }
        
        // calculate all the nodes in a subtree
        
        dfs_count(adj, 0, -1);
        
        // calculate the distances for every node to the other nodes 
        
        dfs_final(adj, 0, -1);
        
        return res;
    }
};


















834. Sum of Distances in Tree
Hard

3069

65

Add to List

Share
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

 

Example 1:


Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.
Example 2:


Input: n = 1, edges = []
Output: [0]
Example 3:


Input: n = 2, edges = [[1,0]]
Output: [1,1]
 

Constraints:

1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
The given input represents a valid tree.

