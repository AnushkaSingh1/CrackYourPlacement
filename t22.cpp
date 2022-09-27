class Solution {
public:
    set<pair<int,int>> res;
    bool flag=false;
    void check(vector<vector<int>>& g,int& val,int prev,int i,vector<bool>& vis,set<pair<int,int>>& sp){
        for(auto el:g[i]){
            if(vis[el] && prev!=val && el==val){
                res=sp;
                flag=true;
                return;
            }
            if(vis[el]) continue;
            vis[el]=true;
            sp.insert({i,el});
            check(g,val,i,el,vis,sp);
            sp.erase({i,el});
            vis[el]=false;
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> g(edges.size()+1);
        for(auto el:edges){
            g[el[0]].push_back(el[1]);
            g[el[1]].push_back(el[0]);
        }
        vector<int> actres;
        set<pair<int,int>> st;
        vector<bool> vis(edges.size()+1,false);
        for(int i=1;i<=edges.size();i++){
            vis[i]=true;
            check(g,i,i,i,vis,st);
            if(flag){
                for(int j=edges.size()-1;j>=0;j--){
                    if(res.find({edges[j][0],edges[j][1]})!=res.end() || res.find({edges[j][1],edges[j][0]})!=res.end()){
                        actres.push_back(edges[j][0]);
                        actres.push_back(edges[j][1]);
                        break;
                    }
                }
                break;
            }
            vis[i]=false;
        }
        return actres;
    }
};


















684. Redundant Connection
Medium

4511

320

Add to List

Share
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.



