  bool canJump(vector<int>& nums) {
        int n=nums.size();
       //dp[i] denotes that is it possible to reach the last index from the ith index or not!
        bool dp[n];
       //initially consider false for every index
        memset(dp,false,sizeof(dp));
       //it is possible to reach last index from last index hence true
        dp[n-1]=true;
        //start from the 2nd last index and move towards 0th index and calcultae the dp array
        for(int i=n-2;i>=0;i--)
        {
            //if the nmbr of jumps is 0 then it is not possible to reach any further index hence false
            if(nums[i]==0)
                dp[i]=false;
            //if the jump takes us to last index or beyond last index then simply true
            else if(nums[i]>=n-1-i)
             dp[i]=true;
            //else we will one by one take jumps and see if taking any of the jump will lead us to the last index or not 
            else
            {
                //start from jump 1 to the available jump i.e nums[i]
                for(int j=1;j<=nums[i];j++)
                {
                    //for every jump find if any of it has true in it or not hence || dp[i] with the dp of index after j jumps i.e dp[i+j]
                     dp[i]=dp[i]||dp[i+j];
                }
            }
        }
       // since we need to return whether it is possible to reach last index from 0th index or not and this will be stored in dp[0] hence return dp[0]
        return dp[0];
    }





























55. Jump Game
Medium

12599

671

Add to List

Share
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
