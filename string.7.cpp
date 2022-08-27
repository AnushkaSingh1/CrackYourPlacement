class Solution {
public:
    void rec(int open,int close,int n,vector<string> &res,string s)
    {
        if(close>open) return ;
        if(open==n && close==n){ res.push_back(s);return ;}
        if(open<n) rec(open+1,close,n,res,s+'(');
        if(close<n) rec(open,close+1,n,res,s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        rec(0,0,n,res,"");
        return res;
    }
};












22. Generate Parentheses
Medium

14769

556

Add to List

Share
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8









