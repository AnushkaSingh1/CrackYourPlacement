class Solution {
public:
    bool solve(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL)
            return true;
        
        if((left==NULL && right!=NULL) || (left!=NULL && right==NULL) || (left->val!=right->val))
            return false;
        
        return solve(left->left,right->right) && solve(left->right,right->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};














bool recursion(TreeNode* left,TreeNode* right){
if(left==NULL && right==NULL)
return true;

    if((left==NULL && right!=NULL) || (left!=NULL && right==NULL) || (left->val!=right->val))
        return false;
    
    return recursion(left->left,right->right) && recursion(left->right,right->left);
    
}

bool isSymmetric(TreeNode* root) {
    return recursion(root->left,root->right);
}













bool helper(TreeNode *left, TreeNode *right) {
    if (!left && !right) {
        return true;
    }
    if (!left || !right || left->val!=right->val) {
        return false;
    }
    return helper(left->left, right->right) && helper(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return helper(root->left, root->right);
}














Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 
