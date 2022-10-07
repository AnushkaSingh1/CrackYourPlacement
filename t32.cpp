class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans1;
        if(root == NULL)
            return ans1;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> ans2(size);
            
            //level process
            for(int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - i - 1;
                ans2[index] = temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            //direction reversal
            leftToRight = !leftToRight;
            ans1.push_back(ans2);
        }
        return ans1;
    }
};


















103. Binary Tree Zigzag Level Order Traversal
Medium

7364

196

Add to List

Share
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100


