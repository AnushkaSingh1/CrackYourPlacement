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
