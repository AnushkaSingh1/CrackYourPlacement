class Solution {
public:
    string addBinary(string a, string b) {
 
        string ans= "";
        int carry=0;
        int n= a.length()-1;
        int m= b.length()-1;
        while(n>=0||m>=0||carry!=0)
        {
            if(m>=0)
            {
            carry=  carry+( b[m]- '0');
                m--;
            }
            if(n>=0)
            {
                carry= carry+ (a[n]-'0');
                    n--;
            }
          
           ans= ans+ (to_string(carry%2) );
            carry= carry/2;
       
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
