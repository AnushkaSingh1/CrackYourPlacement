class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int s, int e){
        if(s <= e ){
            int i = s + (e-s)/2;
            TreeNode* root = new TreeNode(nums[i]);
            root->left = dfs( nums, s, i-1);
            root->right = dfs(nums, i+1, e);   
            return root;
        }
        return NULL; 
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};




















class Solution {
public:
     TreeNode * makeBST(vector<int>&in,int s,int e){
        
        if(s>e)
            return NULL;
        
       int mid = s + (e-s)/2;
       
       TreeNode * root = new TreeNode(in[mid]);  // create root node with in[mid] element
        
        root->left = makeBST(in,s,mid-1);       // create left subtree
        root->right = makeBST(in,mid+1,e);  // create right subtree
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int start  = 0;
        int end  = nums.size() -1 ;
		
        return makeBST(nums,start,end);
    }
};














class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size()-1;
        return CreateBST(nums,0,n);;
        }
    TreeNode* CreateBST(vector<int>& nums,int l,int r){
        if(l>r)
            return NULL;
        int mid=l+(r-l)/2;
    
        TreeNode* Node=new TreeNode(nums[mid]);
        Node->left=CreateBST(nums,l,mid-1);
        Node->right=CreateBST(nums,mid+1,r);
        return Node;
    }
};




















Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
