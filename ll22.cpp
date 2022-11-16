class Solution {
public:
   
    unordered_map<int,string>tens={
        {10,"Ten"},{20,"Twenty"},{30,"Thirty"},{40,"Forty"},
        {50,"Fifty"},{60,"Sixty"},{70,"Seventy"},{80,"Eighty"},{90,"Ninety"}
    };
    
    unordered_map<int,string>powers{
        {3,"Hundred"},{4,"Thousand"},{7,"Million"},{10,"Billion"} 
    };
    
    vector<string>v1={"Zero","One","Two","Three","Four","Five","Six","Seven",
                     "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
                     "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
    
   
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        
        stack<string>s;
        int i=1;
        while(num>0)
        {
            int x=num%10;
            if(x==0)
            {
                if(i==7)
                {
                    if(s.top()==powers[4])
                        s.pop();
                    s.push(powers[i]);
                }
                   
                if(i==4)
                    s.push(powers[i]);
            }
            if(x!=0)
            {
                if(i==1 || i==3 || i==4 || i==7 || i==10)
                {
                    if(i==10 && s.top()=="Million")
                        s.pop();
                    
                    if(i==7 && s.top()=="Thousand")
                        s.pop();
                        
                    
                    if(i!=1)
                        s.push(powers[i]);
                    
                    if((i==1 || i==4 || i==7) && (num/10) !=0)
                    {
                        int k=num/10;
                        int pre=k%10;
                        if(pre==1)
                        {
                            pre= pre*10 + x;
                            s.push(v1[pre]);
                            num/=10;
                            i+=1;
                        }
                        else
                            s.push(v1[x]);
                    }
                    else
                        s.push(v1[x]);
                    
                    
                }
                else if(i==6 || i==9)
                {
                    s.push(powers[3]);
                    s.push(v1[x]);
                }
                else if(i==2 || i==5 || i==8)
                {
                    
                    s.push(tens[x*10]);
                }
                
            }
            num/=10;
            i+=1;
        }
        
        string ans="";
        while(!s.empty())
        {
            ans+=s.top();
            ans+=" ";
            s.pop();
        }
        
        ans.pop_back();
        return ans;
        
    }
};














273. Integer to English Words
Hard

2465

5614

Add to List

Share
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 231 - 1











