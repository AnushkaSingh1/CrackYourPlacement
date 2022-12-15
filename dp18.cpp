class Solution {
public:
    vector<vector<int>> memo;
    int dp(string &s,int i,int j)
    {
        if(i>=j)							//Base case.
            return 0;
        if(memo[i][j]!=-1)					//Check if we have already calculated the value for the pair `i` and `j`.
            return memo[i][j];
        return memo[i][j]=s[i]==s[j]?dp(s,i+1,j-1):1+min(dp(s,i+1,j),dp(s,i,j-1));		//Recursion as mentioned above.
    }
    int minInsertions(string s) 
    {
        memo.resize(s.length(),vector<int>(s.length(),-1));
        return dp(s,0,s.length()-1);
    }
};


















1312. Minimum Insertion Steps to Make a String Palindrome
Hard
2.8K
34
Companies
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.



