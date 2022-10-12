802. Find Eventual Safe States
Medium

2872

340

Add to List

Share
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 

Constraints:

n == graph.length
1 <= n <= 104
0 <= graph[i].length <= n
0 <= graph[i][j] <= n - 1
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 104].
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  class Solution {
public:
bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathVis,vector<int> &check){
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0;
    
    for(auto it:adj[node]){
        if(!vis[it]){ //when the node is not visited
            if(dfs(it,adj,vis,pathVis,check)==true){
                check[node]=0;
                return true;
            }
                
        }
        else if(pathVis[it])//if the node has been previouesly visited 
        {                   //but it has to be visited on same path means its a cycle
            check[node]=0;
            return true;
        }
    }
    
    check[node]=1;
    pathVis[node]=0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V=graph.size();
    vector<int> vis(V,0);
    vector<int> pathVis(V,0);
    vector<int> check(V,0);
    
    vector<int> adj[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<graph[i].size();j++){
            adj[i].push_back(graph[i][j]);//create adj list from graph
        }
    }
    
    for(int i=0;i<V;i++){
        if(!vis[i]){ //if the node is not visted
            dfs(i,adj,vis,pathVis,check);   //then check for all the not vis nodes
        }
    }
    
    vector<int>safeNode;
    for(int i=0;i<V;i++){
        if(check[i]==1){//if check the node is checked then it is safe
            safeNode.push_back(i);
        }
    }
    
    return safeNode;
}

};
  
  
  
  
  
  
  
