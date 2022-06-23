class Solution {
public:
    bool validPalindrome(string s) {
        int p1 = 0;
        int p2 = s.size() - 1;
        int temp = 0;
        while(p2>p1){
            if(s[p2]==s[p1]){
                p2--;
                p1++;
            }
            else{
             temp++;
             p1++;
            }
        }
        if(temp <= 1){
            return true;
        }
        p1 = 0;
        p2 = s.size() - 1;
        temp = 0;
        while(p2>p1){
            if(s[p2]==s[p1]){
                p2--;
                p1++;
            }
            else{
             temp++;
             p2--;
            }
        }
        return (temp <= 1) ? true : false;
        
    }
};










class Solution {
public:
    bool check(string &s, int b, int e){
      while(b<e){
        if(s[b] != s[e])
          return false;
        b++;e--;
      }
      return true;
    }
    bool validPalindrome(string s) {
      int b = 0;
      int e = s.length()-1;
      bool deleted = false;
      while(b<e){
        if(s[b] == s[e]){
          b++;e--;
        }else{
          return check(s, b+1, e) or check(s, b, e-1);
        }
      }
      return true;
    }
};










Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
