class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        // we are calculating what frequencies do we need to have substring window
        for(int i = 0; i < t.size(); i++){
            freq[t[i]]++;
        }
        // we assume that whole s is our substring window and decrease frequencies for letters we have
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]--;
        }
        // if we do not have certain letters then we return ""
        for(auto it: freq){
            if(it.second > 0){
                return "";
            }
        }
        // we now trying to make minimum window substring that have left side on 0
        int l = 0;
        int r = s.size()-1;
        while(freq[s[r]] < 0){
            freq[s[r]]++;
            r--;
        }
        int best_length = r-l + 1;
        int best_l = l;
        // we now trying to make minimum window substring
        while(r < s.size()){
            // if it is possible we try to minimize left 
            if(freq[s[l]] < 0){
                freq[s[l]]++;
                l++;
                // whenever we minimize from the left then we can check if it is minimum and save result
                if(r-l+1 < best_length){
                    best_length = r-l+1;
                    best_l = l;
                }
            } else {
                // if not we have to increase right
                r++;
                freq[s[r]]--;
            }
        }
        return s.substr(best_l, best_length);
    }
};



















76. Minimum Window Substring
Hard

13658

600

Add to List

Share
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
