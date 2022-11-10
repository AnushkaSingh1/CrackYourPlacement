class Solution {
public:

    #define ll long long

    ll merging(vector<ll>&prefix,vector<ll>&temp,ll start,ll mid,ll end,int lower,int upper){
        ll j=mid,k=mid,count=0,i;
        for(ll i=start;i<mid;i++){
            while(j<=end && prefix[j]-prefix[i]<lower){
                j++;
            }
            while(k<=end && prefix[k]-prefix[i]<=upper){
                k++;
            }
            count+=(k-j);
        }
        i=start,j=mid,k=start;
        while(i<=mid-1 && j<=end){
            if(prefix[i]<=prefix[j]){
                temp[k++]=prefix[i++];
            }
            else{
                temp[k++]=prefix[j++];
            }
        }
        while(i<=mid-1){
            temp[k++]=prefix[i++];
        }
        while(j<=end){
            temp[k++]=prefix[j++];
        }
        for(ll i=start;i<=end;i++){
            prefix[i]=temp[i];
        }
        return count;
    }

    ll merge(vector<ll>&prefix,vector<ll>&temp,ll start,ll end,int lower,int upper){
        ll answer=0,mid;
        if(start==end){
            if(prefix[start]>=lower && prefix[start]<=upper){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(start<end){
            mid=(start+end)>>1;
            answer+=merge(prefix,temp,start,mid,lower,upper);
            answer+=merge(prefix,temp,mid+1,end,lower,upper);
            answer+=merging(prefix,temp,start,mid+1,end,lower,upper);
        }
        return answer;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
       ll n=nums.size();
       vector<ll>prefix(n,0);prefix[0]=nums[0];
       for(ll i=1;i<n;i++){
           prefix[i]=prefix[i-1]+nums[i];
       }
       vector<ll>temp(n);
       return merge(prefix,temp,0,n-1,lower,upper);
    }
};






























327. Count of Range Sum
Hard

1862

196

Add to List

Share
Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

 

Example 1:

Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
Example 2:

Input: nums = [0], lower = 0, upper = 0
Output: 1
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
-105 <= lower <= upper <= 105
The answer is guaranteed to fit in a 32-bit integer.
