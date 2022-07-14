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
















class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string output = "";
        
        helper(ans, output, root);
        return ans;
    }
    void helper(vector<string>&ans, string output, TreeNode*root){
        if(root->left == NULL and root->right==NULL)    //This is a leaf node
        {
			output += to_string(root->val);  
			// to_string() function converts integer to string and if we do not use this function and directly push the root->val then all the elements of string will be appended by \u000 which will cause the answer to be incorrect
            ans.push_back(output);
            return;
        }
        output += to_string(root->val);
        output += "->";
        if(root->left) helper(ans, output, root->left);
        if(root->right) helper(ans, output, root->right);
        return;
    }
};














Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
