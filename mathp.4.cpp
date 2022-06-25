class Solution {
public:
    string convertToTitle(int c) {
        string ans;
        int r;
        
        while(c!=0)
        {
           c= c-1;  // decrement column index by 1 so that A->0 .... Z->25
           r=c%26;
           ans.push_back(r +'A');   // store the modulo in  ans
           c=c/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};












class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;        
        while(columnNumber--){          
            ans= char('A'+columnNumber%26)+ans;
            columnNumber/=26;
        }
        return ans;
    }
};














Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
