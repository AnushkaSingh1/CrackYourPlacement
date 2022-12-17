class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        if( (stones.size()-1)%(K-1) ) return -1;
        vector<int> p;
        p.resize(stones.size()+1);
        p[0]= 0;
        partial_sum(stones.begin(), stones.end(), p.begin()+1);
        
        unordered_map<long, int> memo;
    
        return rangeCost(0, stones.size(), p, K, memo);
    }
    
    int rangeCost(int is, int ie, vector<int>& partial_stones, int K, unordered_map<long,int> &memo){
        if(ie-is==1) return 0;
        return partitionCost(is, ie, K, partial_stones, K, memo) + partial_stones[ie] - partial_stones[is];    
    }
    
    int partitionCost(int is, int ie, int n, vector<int>& partial_stones, int K, unordered_map<long,int> &memo){
        long key= is*(K+1)*(long)partial_stones.size()+ie*(K+1) + n; //n remaining partitions and range encoded
        
        if(memo.count(key)) return memo[key];
        int best= 1e9;        
        
        if(n==1) 
            best= rangeCost(is, ie, partial_stones, K, memo);
        else
            for(int i=is+1; i<ie; i+=K-1)
                best= min(best, rangeCost(is, i, partial_stones, K, memo) + partitionCost(i, ie, n-1, partial_stones, K, memo));
        
        memo[key]= best;
        return best;
    }
};















1000. Minimum Cost to Merge Stones
Hard
2K
94
Companies
There are n piles of stones arranged in a row. The ith pile has stones[i] stones.

A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.

Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.

 

Example 1:

Input: stones = [3,2,4,1], k = 2
Output: 20
Explanation: We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.
Example 2:

Input: stones = [3,2,4,1], k = 3
Output: -1
Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
Example 3:

Input: stones = [3,5,1,2,6], k = 3
Output: 25
Explanation: We start with [3, 5, 1, 2, 6].
We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
We merge [3, 8, 6] for a cost of 17, and we are left with [17].
The total cost was 25, and this is the minimum possible.
 

Constraints:

n == stones.length
1 <= n <= 30
1 <= stones[i] <= 100
2 <= k <= 30














