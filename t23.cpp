#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;

        if(root == NULL)    return ans;

        queue<TreeNode*> nodes;

        nodes.push(root);

        int n = 1;

        while(!nodes.empty()){

            int count = 0;
            vector<int> vec;
            
            for(int i = 0 ; i < n ; i++){

                TreeNode* temp = nodes.front();
                nodes.pop();

                vec.push_back(temp->val);

                if(temp->left != NULL){
                    nodes.push(temp->left);
                    count++;
                }

                if(temp->right != NULL){
                    nodes.push(temp->right);
                    count++;
                }

            }

            n = count;
            ans.push_back(vec);
        }

        return ans;
    }
};



















102. Binary Tree Level Order Traversal
Medium

10940

207

Add to List

Share
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000




