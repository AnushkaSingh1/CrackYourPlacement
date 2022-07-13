class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};













int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return max( 1+maxDepth(root->left), 1+maxDepth(root->right));
}

























class Solution {
public:
int maxDepth(TreeNode* root) {
if(root==NULL)
return 0;
queue<TreeNode*>q;
int count=0;
q.push(root);
while(!q.empty()){
count++;
int size=q.size();
for(int i=0;i<size;i++){
TreeNode* curr=q.front();
q.pop();
if(curr->left!=NULL)
q.push(curr->left);
if(curr->right!=NULL)
q.push(curr->right);
}
}
return count;
}
};














class Solution {
public:

int maxDepth(TreeNode* root) {
    if(root==NULL)
        return 0;
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}
};
