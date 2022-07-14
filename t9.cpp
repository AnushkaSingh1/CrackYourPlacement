class Solution {
	vector<string> ans;
private:
	void f(TreeNode* root, string s) {
		if (!root) return;
		if (!root->left && !root->right) {
			string x = to_string(root->val);
			s += x;
			ans.push_back(s);
			return;
		}
		string x = to_string(root->val) + "->";
		s += x;
		f(root->left, s);
		f(root->right, s);
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		string s;
		f(root, s);
		return ans;
	}
};














class Solution {
public:
    void Paths(TreeNode*root,string temp,vector<string>&ans)
    {if(root==NULL) // if node is not leaf node it will be returned
        return;
        if(root->left==NULL&&root->right==NULL){// if node is leaf node it is last node of the every paths
          temp+='-';    
            temp+='>';
         temp+=to_string(root->val);  
        ans.push_back(temp);
            return ; }
        if(temp.length()==0)                   // for fist element we cant put->
            temp+=to_string(root->val);
        else                                        // for all element after first we put ->
        {   temp+='-';    
            temp+='>';
         temp+=to_string(root->val);
    }
        Paths(root->left,temp,ans);  // traverse left 
        Paths(root->right,temp,ans);// traverse right
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp=""; // for storing temp paths
        vector<string> ans; // for storing all paths to leaf not
        if(root->left==NULL&&root->right==NULL){ // if root node is a leaf node
            temp=to_string(root->val);
            ans.push_back(temp);
            return  ans;
        }
        Paths(root,temp,ans);    // finding all paths
        return ans;  // return all paths
    }
};
