class Solution {
public:
    void searchPath(TreeNode* root, vector<TreeNode*>& path, TreeNode* search_node) {
        while(root) {
            if(search_node->val < root->val) {
                path.push_back(root);
                root = root->left;
            } else if(search_node->val > root->val) {
                path.push_back(root);
                root = root->right;
            } else {
                path.push_back(root);
                break;
            }
        }
    }
    TreeNode* findCommonNode(vector<TreeNode*> p, vector<TreeNode*> q) {
        TreeNode* ret;
        unordered_set<TreeNode*> st;
        
        for(TreeNode* n : q){
            st.insert(n);
        }
        for(TreeNode* n : p){
            if(st.find(n)!=st.end()){
                ret = n;
            }
        }
        return ret;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_P, path_Q;
        searchPath(root, path_P, p);
        searchPath(root, path_Q, q);
        return findCommonNode(path_P,path_Q);
    }
};


















class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root==p || root==q)     return root;
    TreeNode *left = lowestCommonAncestor(root->left,p,q);
    TreeNode *right = lowestCommonAncestor(root->right,p,q);
    if(!left)   return right;
    else if(!right)     return left;
    return root;
}
};

















Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
