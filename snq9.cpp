class Solution {
public:
    
    vector<long long int> nsr(vector<int>& arr){
        stack<long long int> s;
        long long int n = arr.size();
        vector<long long int> ans(n, n);
        
        
        for(long long int i=n-1;i>=0; i--)
        {
            if(s.empty()){
                ans[i] = n;
                s.push(i);
                continue;
            }
            
            if(!s.empty() && arr[s.top()] <= arr[i] ) ans[i] = s.top();
            
            if(!s.empty() && arr[s.top()] > arr[i]) {
                while(!s.empty() && arr[s.top()] > arr[i]){
                    s.pop();
                } 
                
                if(s.empty()) ans[i] = n;
                else ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    
    vector<long long int> nsl(vector<int>& arr){
        stack<long long int> s;
        long long int n = arr.size();
        vector<long long int> ans(n, -1);
        
        for(long long int i=0;i<n;i++)
        {
            if(s.empty()){
                ans[i] = -1;
                s.push(i);
                continue;
            }
            
            if(!s.empty() && arr[s.top()] < arr[i] ) ans[i] = s.top();
            
            if(!s.empty() && arr[s.top()] >= arr[i]) {
                while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
                
                if(s.empty()) ans[i] = -1;
                else ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    
    
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<long long int> nsre = nsr(arr);
        vector<long long int> nsle = nsl(arr);
        
        long long int ans = 0;
        long long int MOD = 1000000007;
        
        for(int i=0;i<arr.size(); i++){
            
            ans += arr[i] * (i - nsle[i]) * (nsre[i]-i);
            ans %= MOD;
        }
        return ans;
        
        
        
    }
};
















907. Sum of Subarray Minimums
Medium

4210

278

Add to List

Share
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104



