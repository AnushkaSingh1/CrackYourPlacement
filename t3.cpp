class Solution {
public:
    void getIn(TreeNode* root, string &st){
        if(root==NULL) {
            st = st + "#";
            return ;
        }
        getIn(root->left,st);
        st = st + to_string(root->val);
        getIn(root->right,st);
    }
    void getPre(TreeNode* root, string &st){
        if(root==NULL) {
            st = st + "#";
            return ;
        }
        st = st + to_string(root->val);
        getPre(root->left,st);
        getPre(root->right,st);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string pR="",pS="",iR="",iS="";
        getIn(root,iR);
        getIn(subRoot,iS);
        
        if(iR.find(iS)==string::npos) return false;
        
        getPre(root,pR);
        getPre(subRoot,pS);

        
        if(pR.find(pS)!=string::npos) return true;
        return false;
    }
};

















class Solution {
public:

bool isIdentical(TreeNode *root, TreeNode *subRoot){
    if(subRoot==NULL && root==NULL)
        return true;
    if(subRoot==NULL || root==NULL)
        return false;
    if(root->val==subRoot->val)
        return isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
    
    return false;
}


bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(subRoot==NULL)
        return true;
    if(root==NULL)
        return false;
    if(root->val==subRoot->val){
        if(isIdentical(root, subRoot))
            return true;
    }
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    
}
};


















bool isSameTree(TreeNode* p, TreeNode* q) {

    if(p==nullptr && q==nullptr){return true;}
    if(p==nullptr && q!=nullptr){return false;}
    if(q==nullptr && p!=nullptr){return false;}
    if(p->val!=q->val){return false;}
    
    bool left=isSameTree(p->left,q->left);
    bool right=isSameTree(p->right,q->right);
    
    return left && right;
    
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    
    if(!root){return false;}
    if(!subRoot){return true;}
    
    if(isSameTree(root,subRoot)){return true;}
    
    bool left=isSubtree(root->left,subRoot);
    bool right=isSubtree(root->right,subRoot);
    
    return left || right;
    
}

















class Solution {
public:
    
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(!root and !subRoot)return true;
        if(!root or !subRoot)return false;
        if(root->val==subRoot->val){
            return solve(root->left,subRoot->left) and solve(root->right,subRoot->right);
        }
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)return true;
        if(!root)return false;
        if(root->val==subRoot->val){
            if(solve(root,subRoot))
                return true;
        }
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};
















Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 

Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
