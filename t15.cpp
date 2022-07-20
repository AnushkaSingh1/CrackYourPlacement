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





