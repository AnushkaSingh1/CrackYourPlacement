class Solution
{
public:
	vector<vector<int>> ans;

	void helper(int idx, int k, vector<int> &current, int n)
	{
		if (current.size() == k)
		{
			ans.push_back(current);
			return;
		}

		for (int i = idx; i < n + 1; i++)
		{
			current.push_back(i);
			helper(i + 1, k, current, n);
			current.pop_back();
		}
	}

	vector<vector<int>> combine(int n, int k)
	{
		vector<int> current;
		helper(1, k, current, n);
		return ans;
	}
};

















77. Combinations
Medium

5248

166

Add to List

Share
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 

Constraints:

1 <= n <= 20
1 <= k <= n
