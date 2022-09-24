class Solution {
public:
    /*
        convert tree to a undirected graph
    */
    unordered_map<TreeNode*, vector<TreeNode*>> g;
    vector<int> res;
    
    void dfs(TreeNode* root) {
        if (root->left) {
            auto left = root->left;
            g[left].push_back(root);
            g[root].push_back(left);
            dfs(left);
        }
        if (root->right) {
            auto right = root->right;
            g[right].push_back(root);
            g[root].push_back(right);
            dfs(right);
        }
    }
    
    void bfs(TreeNode* target, int k) {
        unordered_set<TreeNode*> st;
        queue<TreeNode*> que;
        que.push(target);
        st.insert(target);
        
        int dist = 0;
        while (que.size()) {
            int sz = que.size();
            while (sz--) {
                auto a = que.front();
                que.pop();
                
                if (dist == k) res.push_back(a->val);
                
                for (auto b : g[a]) {
                    if (st.count(b)) continue;
                    st.insert(b);
                    que.push(b);
                }
            }
            dist++;
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        bfs(target, k);
        return res;
    }
};














863. All Nodes Distance K in Binary Tree
Medium

7422

146

Add to List

Share
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000







