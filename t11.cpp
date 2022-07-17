class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      
        if (root == NULL)
            return false;
        
        if (root -> left == NULL and root -> right == NULL and root -> val == targetSum)
            return true;
        
        return hasPathSum(root -> left, targetSum - root -> val) or hasPathSum(root -> right, targetSum - root -> val);
        }

};












class Solution {
public: bool check(TreeNode* root, int target,int sum,bool &ans){
    
    if(ans){
        return true;
    }
    if((!root->left && !root->right) && (sum==target))
    {
        ans=true;
        return ans;
    }
    if(root->left)
    check(root->left,target,root->left->val +sum,ans);
    if(root->right)
    check(root->right,target,root->right->val+sum, ans);
    return ans;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        bool ans=false;
        return (check(root,targetSum,root->val,ans));
        
        
    }
};



















Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000













