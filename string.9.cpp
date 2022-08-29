class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        s = " "+s + " ";
        int n = s.length(),ptr = 0;
        while(ptr!=n-1){
            if(s[ptr] == ' ' && s[ptr+1]!=' '){
                ptr++;
                string temp = "";
                while(s[ptr]!=' '){
                    temp+=s[ptr];
                    ptr++;
                }
                st.push(temp);
            }
            else{
                ptr++;
            }
        }
        string res = "";
        n = st.size();
        for(int i=0;i<n;i++){
            res+=st.top();
            if(i!=n-1)
                res+=" ";
            st.pop();
        }
        return res;
    }
};
























151. Reverse Words in a String
Medium

3803

4092

Add to List

Share
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?












