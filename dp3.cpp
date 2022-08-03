class Solution {
public:
    map<int,pair<int,int>> mp;
    int dp[610][105][105];
    int helper(int m,int n,int len ,int i){
        if(i==len){
            return 0;
        }
        int cnt0=mp[i].first;
        int cnt1=mp[i].second;
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int opt1;
        if(m-cnt0>=0 && n-cnt1>=0){
            opt1=1+helper(m-cnt0,n-cnt1,len,i+1);
        }
        else{
            opt1=0;
        }
        int opt2=helper(m,n,len,i+1);
        return dp[i][m][n]=max(opt1,opt2);
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        int len=s.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<len;i++){
            int cnt0=0;
            int cnt1=0;
            for(int j=0;j<s[i].length();j++){
                if(s[i][j]=='0'){
                    cnt0++;
                }
                else{
                    cnt1++;
                }
            }
            mp[i]=make_pair(cnt0,cnt1);
        }
        int ans=helper(m,n,len,0);
        return ans;
    }
};




















You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100

