class Solution {
public:
int camera = 0;
int solve(TreeNode* root){

    //Agar root null hai iska matlab camera nhi chahiye vo covered hai
    if(root==NULL){
        return 1;
    }
    
    int left = solve(root->left);
    int right = solve(root->right);
    
    if(left == -1 || right == -1){
        camera++;
        //return 0 ka mtlb ki yha camera lg gya
        return 0;
    }
    else if(left == 0 || right == 0){
        //Yha camera nhi hai but ue covered hai..
        //inke bcho me se kisi ke paas hai camera
        return 1;
    }
    
        //ab iske paas na camera hai aur na ye covered hai
        //to ye apne parent ko bolegi ki isse camera chahiye
        return -1;
    
}
int minCameraCover(TreeNode* root) {
    //3 case bnenge
    //Case 1 : Agar tume camera ke need hai to  -1;
    //Case 2 : Agar camera jha lga hua hai vha 0;
    //Case 3 : Yha camera nahi lga hua but tum covered ho vha  1;
    if(solve(root)==-1){
        camera++;
    }
    return camera;
}
};

















968. Binary Tree Cameras
Hard

4588

62

Add to List

Share
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
