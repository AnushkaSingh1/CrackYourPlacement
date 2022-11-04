class Solution {
public:
    bool seen[16] = {};
    int res = 0;
    int countArrangement(int n, int pos = 1) {
        if (n < 4) return n;
        if (pos > n) return res++;
        for (int i = 1; i <= n; i++) {
            if (!seen[i] && (i % pos == 0 || pos % i == 0)) {
                // marking i as seen
                seen[i] = true;
                countArrangement(n, pos + 1);
                // backtracking
                seen[i] = false;
            }
        }
        return res;
    }
};
















526. Beautiful Arrangement
Medium

2594

319

Add to List

Share
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 15

