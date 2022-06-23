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
