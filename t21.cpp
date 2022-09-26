class Solution
{
public:
   vector<int> rightSideView(TreeNode *root)
   {
       ios_base::sync_with_stdio(0);
       cin.tie(0);
       // Make ans vector
       vector<int> ans;
       if (root == NULL)
       {
           return ans;
       }
       // Create map to store first right value for each level
       map<int, int> mp;
       
       // Make queue This queue will hold Node and level
       queue<pair<TreeNode *, int>> q; 
       
       // For root level will be 0
       q.push(make_pair(root, 0));
       while (!q.empty())
       {
           pair<TreeNode *, int> temp = q.front();
           q.pop();
           
           // Extract front node and level 
           TreeNode *frontNode = temp.first;
           int lvl = temp.second;
           
           // Only store first Node from right for each level in map
           if (mp.find(lvl) == mp.end())
           {
               mp[lvl] = frontNode->val;
           }
           
           // First process right part
           if (frontNode->right)
           {
               q.push(make_pair(frontNode->right, lvl + 1));
           }
           //Then process left part
           if (frontNode->left)
           {
               q.push(make_pair(frontNode->left, lvl + 1));
           }
       }
       for (auto i : mp)
       {
           ans.push_back(i.second);
       }
       return ans;
   }
};























199. Binary Tree Right Side View
Medium

8624

501

Add to List

Share
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100




