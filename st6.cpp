class Solution {
public:

    int numDistinct(string s1, string s2) {
        int prime = 1e9+7;
        int m = s1.length();
        int n = s2.length();
        int k = max(m,n);
        vector<int> prev(k+1,0);
        
    //Base Case

      prev[0]=1;

      for(int i=1;i<m+1;i++){
          for(int j=n;j>=1;j--){
                //Condition for match
                if(s1[i-1]==s2[j-1]){
                    prev[j] =  (prev[j-1]+prev[j])%prime;
                }
          }
      }
      return prev[n];

    }
};















115. Distinct Subsequences
Hard

4673

189

Add to List

Share
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
