int ans=1;
    
    int checkheight(TreeNode * root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=checkheight(root->left);
        int r=checkheight(root->right);
        
        if(abs(l-r)>1)
        {
            ans=0;
        }
        return 1+max(l,r);
    }
    
    bool isBalanced(TreeNode* root) {
        
       checkheight(root);
        return ans;
        
        
        
    }


















class Solution {
public:
    pair<int,bool> heightbalanced(TreeNode* root)
    {
        if(root==0)
        {
            pair<int,bool>p;
            p.first=0;
            p.second=true;
            return p;
        }
        pair<int,bool> r,l=heightbalanced(root->left);
        if(!l.second){return l;}
        r=heightbalanced(root->right);
        if(!r.second){return r;}
        else
        {
            if(r.first-l.first>1 ||r.first-l.first<-1)
            {
                r.second=0;
                return r;
            }
            else
            {
                r.first=1+max(r.first,l.first);
                return r;
            }
        }
    }    
    bool isBalanced(TreeNode* root) 
    {
        pair<int,bool>p;
        p=heightbalanced(root);
        if(p.second==true){return true;}
        return false;
    }              
}; 


























110. Balanced Binary Tree
Easy

6570

344

Add to List

Share
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
