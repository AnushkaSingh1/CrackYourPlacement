class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* newNode = new TreeNode(root->val);
        newNode->left =  invertTree(root->right);
        newNode->right = invertTree(root->left);
        return newNode;
    }
};
















class Solution {
public:
    
    void solve(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        solve(root->left);
        solve(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        
        solve(root);
        
        return root;
        
    }
};




















class Solution {
public:
    void reverse(TreeNode* root){
        if(root==0) return;
        if(root->left!=0||root->right!=0){
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=temp;
        }
        reverse(root->left);
        reverse(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        reverse(root);
        return root;
    }
};




















class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode* lt= root->left;
        TreeNode* rt= root->right;
        
        invertTree(root->left);
        invertTree(root->right);
        
        root->left= rt;
        root->right= lt;
        
        return root;
    }
};



















Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
