TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL || root2==NULL)
          return root1?root1:root2;
        TreeNode *root=new TreeNode(root1->val + root2->val);
        root->left=mergeTrees(root1->left,root2->left);
        root->right=mergeTrees(root1->right,root2->right);
        return root;
    }
















class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2){//if both are NULL then return NULL
            return NULL;
        }
        if(!root1){ //if root1 is NULL then return root2
            return root2;
        }
        if(!root2){//if root2 is NULL then return root1
            return root1;
        }
        //if root1 and root2 are not NULL
        //using root1 to make the final tree
        //adding root2 into root1
        root1->val+=root2->val;
        root1->left=mergeTrees(root1->left,root2->left); //call on left subtree
        root1->right=mergeTrees(root1->right,root2->right); //call on right subtree
        return root1; //return the root1 as the final tree
    }
};






















TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 && root2) root1->val += root2->val;
    else if(!root1 && root2){return root2;}
    else if(root1 && !root2){return root1;}
    else return NULL;
    
    root1->left = mergeTrees(root1->left, root2->left);
    
    root1->right = mergeTrees(root1->right, root2->right);
    
    return root1;
    
}

























You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.

 

Example 1:


Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]
 

Constraints:

The number of nodes in both trees is in the range [0, 2000].
-104 <= Node.val <= 104
