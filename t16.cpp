class Solution {
public:
    
    
    vector<int> treedata;
    
    // preorder recurcive fn
    void inorder(TreeNode* node){
        if (node == NULL) return;
        
        // apply left 
        inorder(node-> left);
        
        // push the data
        treedata.push_back(node-> val);
        
        // apply left 
        inorder(node-> right);
        
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        if (root == NULL) return treedata;
        inorder(root);
        
        return treedata;
    }
};












void inTraversal(TreeNode* root,vector<int>& arr)
     {
         if(root==NULL)
            return ; 
         inTraversal(root->left,arr);
         arr.push_back(root->val);
         inTraversal(root->right,arr);
     }
    vector<int> inorderTraversal(TreeNode* root) {
           vector<int> ans;
           inTraversal(root,ans);
          return ans;
    }





















Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
