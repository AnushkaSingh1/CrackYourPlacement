class Solution {
public:

string longestCommonPrefix(vector<string>& strs) {
       string output = "";
       
       for(int i = 0; i < strs[0].size(); i++){
           char curr = strs[0][i];
           for(int j = 0; j < strs.size(); j++){
               if(strs[j][i] != curr)
                   return output;
           }
           
           output.push_back(curr);
       }
        
       return output; 
}
};







class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string ans="";
        string start=strs[0],end=strs[n-1];
        for(int i=0;i<start.size();i++)
        {
            if(start[i]==end[i])
            {
                ans+=start[i];
            }
            else break;
        }
        return ans;
    }
};
















Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
