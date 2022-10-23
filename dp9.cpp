class Solution { // Time : O(N*M), Space : O(N*M) + Auxilary Space of recursion stack
public: 
    int dp[13][10001];
    int findLowestCoins(vector<int> &coins, int cur, int amount) 
    {
        if(cur==0)
            return (amount%coins[0]==0) ? amount/coins[0] : 1e9;
        if(dp[cur][amount]!=-1)
            return dp[cur][amount];
        int doNotTakeCoin = 0 + findLowestCoins(coins, cur-1, amount);
        int takeCoin = INT_MAX;
        if(coins[cur] <= amount) 
            takeCoin = 1 + findLowestCoins(coins, cur, amount-coins[cur]);
        return dp[cur][amount] = min(takeCoin, doNotTakeCoin);
    }
    int coinChange(vector<int> &coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int res = findLowestCoins(coins, coins.size()-1, amount);
        return (res >= 1e9) ? -1 : res;
    }
};











322. Coin Change
Medium

14333

319

Add to List

Share
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104




