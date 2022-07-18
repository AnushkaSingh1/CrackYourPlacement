class Solution {
public:
    vector<int> vals;
    
    int getMinimumDifference(TreeNode* root) {
        recurse(root);
        sort(vals.begin(), vals.end());
        int res = INT_MAX;
        
        for(int i = 1; i < vals.size(); i++){
            res = min(res, abs(vals[i] - vals[i - 1]));
        }
        return res;
    }
    
    void recurse(TreeNode* root){
        vals.push_back(root->val);
        if(root->left)  recurse(root->left);
        if(root->right) recurse(root->right);
    }
};













class Solution {
private:
    TreeNode* prev=NULL;
    int ans = INT_MAX;
	void f(TreeNode* root) {
		if (root->left) f(root->left);
        if(prev) ans = min(ans, abs(root->val - prev->val));
        prev = root;
		if (root->right) f(root->right);
	}
public:
	int getMinimumDifference(TreeNode* root) {
		f(root);
		return ans;
	}
};

















Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
 

Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

Accepted
167,277
Submissions
296,412
Seen this question in a real interview before?

Yes

No
