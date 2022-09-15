class Solution {
    int dp[41][41];
	int f(int l, int r, vector<int>& a, map<pair<int, int>, int> &m) {
		if (l == r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
		int ans = INT_MAX;
		for (int i = l; i < r; ++i) {
			ans = min(ans , m[{l, i}] * m[{i + 1, r}] + f(l, i, a, m) + f(i + 1, r, a, m));
		}
		return dp[l][r] = ans;
	}
public:
	int mctFromLeafValues(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
		map<pair<int, int>, int> m; // i to j max is value;
		int n = arr.size();
		for (int i = 0; i < n; ++i) {
			m[ {i, i}] = arr[i];
			for (int j = i + 1; j < n; ++j) {
				m[ {i, j}] = max(arr[j], m[ {i, j - 1}]);
			}
		}
		return f(0, n - 1, arr, m);
	}
};


















1130. Minimum Cost Tree From Leaf Values
Medium

3496

236

Add to List

Share
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

 

Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
Example 2:


Input: arr = [4,11]
Output: 44
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).









