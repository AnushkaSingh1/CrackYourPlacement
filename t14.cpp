class Solution {
public:
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (not root->left and not root->right)
            return 0;
        
        helper(root);
        return sum;
    }
    
    void helper(TreeNode* root, bool isleft = false) {
        if (not root) return;
        if (isleft and (not root->left and not root->right))
            sum += root->val;
        helper(root->left, true);
        helper(root->right);
    }
};


















class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(!root) return 0;
        if(root->left && !root->left->left && !root->left->right) sum += root->left->val;
        if(root->left) sum += sumOfLeftLeaves(root->left);
        if(root->right) sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};















Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000









