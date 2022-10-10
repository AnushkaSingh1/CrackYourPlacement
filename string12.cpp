class Solution {
public:
    bool isSubSeq(string str1, string str2, int m, int n) 
{ 
    // Base Cases 
    if (m == 0) return true; 
    if (n == 0) return false; 
    // If last characters of two strings are matching 
    if (str1[m-1] == str2[n-1]) 
        return isSubSeq(str1, str2, m-1, n-1); 
    // If last characters are not matching 
    return isSubSeq(str1, str2, m, n-1); 
} 
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        return isSubSeq(s,t,m,n);
    }
};


















392. Is Subsequence
Easy

5963

338

Add to List

Share
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?




