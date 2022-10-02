class Solution {
public:
    
    void extract(TreeNode* root, vector<int> &nums)
    {
        if(root == NULL) return;
        
        extract(root->left, nums);
        nums.push_back(root->val);
        extract(root->right, nums);
        
    }
    
    void replace(TreeNode* root, vector<int> &nums, int* index)
    {
        if(root == NULL) return;
        
        replace(root->left, nums, index);
        root->val = nums[*(index)];
        *(index) += 1;
        replace(root->right, nums, index);
    }
    
    void recoverTree(TreeNode* root) {
        
        vector<int> nums;
        int index = 0;
        extract(root, nums);
        sort(nums.begin(), nums.end());
        replace(root, nums, &index);
    }
};













99. Recover Binary Search Tree
Medium

6169

206

Add to List

Share
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1



