class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>s1;
        stack<int>s2;
        for(char c:s){
            if(c!='#'){
                s1.push(c);
            }
            else{
                if(!s1.empty()){
                    s1.pop();
                }
            }
        }
        for(char c:t){
            if(c!='#'){
                s2.push(c);
            }
            else{
                if(!s2.empty()){
                    s2.pop();
                }
            }
        }
        if(s1==s2){
            return true;
        }
        return false;
    }
};


















class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=0;   
        while(i<s.size())
        {
            if(s[i]=='#')
            {
                if(i==0)
                {
                    s.erase(i,1);   //delete the element present at ith index only.
                }
                else
                {
                    s.erase(i-1,2);   //delete the element present in the ith index as well as the i-1th index.
                        i--;          //we will move the pointer 1 place back after deleting i.e. at the i-1th index.
                }
            }
            else
            {
                i++;    
            }
        }
        i=0;
         while(i<t.size())
        {
            if(t[i]=='#')
            {
                if(i==0)
                {
                    t.erase(i,1);
                }
                else
                {
                    t.erase(i-1,2);
                        i--;
                }
            }
            else
            {
                i++;
            }
        }
        return s==t;
    }
};




















class Solution {
public:
    
    bool backspaceCompare(string s, string t) {
        stack< char > s1;
        stack < char > s2;
        for(int i=0; i<s.size(); i++){
            if(s[i] != '#')
                s1.push(s[i]);
            else if(!s1.empty())
                s1.pop();
        }
        for(int i=0; i<t.size(); i++){
            if(t[i] != '#')
                s2.push(t[i]);
            else if(!s2.empty())
                s2.pop();
        }
        if(s1.size()!= s2.size())
            return 0;
        while(!s1.empty()){
            if(s1.top() != s2.top())
                return 0;
            else{
                s1.pop();
                s2.pop();
            }
        }
        return 1;
    }
};



















Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
