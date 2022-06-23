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
