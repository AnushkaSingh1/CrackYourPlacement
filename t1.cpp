class Solution {
public:
    pair<int,int> solve(TreeNode* root){
      if(root==NULL)
        return make_pair(0,0);
      pair<int,int> left=solve(root->left);
      pair<int,int> right=solve(root->right);
      int leftDiameter=left.first;
      int leftHeight=left.second;
      int rightDiameter=right.first;
      int rightHeight=right.second;
      
      int ht=1+max(leftHeight,rightHeight);
      int diameter=max(leftDiameter,max(rightDiameter,leftHeight+rightHeight));
      
      return make_pair(diameter,ht);
  }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};

















int d=0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        util(root);
        return d;
        
    }
    int util(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int l=util(root->left);
        int r=util(root->right);
        
        d=max(d,l+r);
        
        return max(l,r)+1;
    }
















class Solution {
    int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        function<int(TreeNode*)> dfs = [&](TreeNode* root)
        {
            if(!root) return 0;
            const int l = dfs(root->left);
            const int r = dfs(root->right);
        
            ans = max(ans, l + r);
            return 1 + max(l, r);
        };
        
        dfs(root);
        return ans;
    }
};












Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
