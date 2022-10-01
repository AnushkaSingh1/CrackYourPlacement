96. Unique Binary Search Trees
Medium

8212

321

Add to List

Share
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  class Solution {

int catalan(int n){
    if(n<=1){
        return 1;
    }
    
    int res = 0;
    
    for(int i=0;i<n;i++){
        res += catalan(i) * catalan(n-i-1);
    }
    
    return res;
}
public:

int numTrees(int n) {
    int ans = catalan(n);
    
    return ans;
}
};
  
  
  
  
  
  
  
  
