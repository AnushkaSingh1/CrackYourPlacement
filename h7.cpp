vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        stack<int> s;
        for(int i=0;i<n;i++){
		//here s.size()-1+(n-i)>=k is for checking that if we remove an element than whether //their be sufficient elements remaining for make size k
            while(!s.empty()&&nums[i]<s.top()&&s.size()-1+(n-i)>=k){
                s.pop();
            }
            if(s.size()<k)
              s.push(nums[i]);
        }
        while(!s.empty()){
            ans.push_back(s.top());s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }















class Solution {
public:

vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> ans;
    int n = nums.size();
    
    for(int i=0; i<n; ++i){
        while(!ans.empty() and ans.back() > nums[i] and (ans.size() - 1) + (n-i) >= k){
            ans.pop_back();
        }
        if(ans.size() == k and nums[i] >= ans.back()) continue;
        ans.push_back(nums[i]);
    }
    
    return ans;
}
};

















Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

 

Example 1:

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
Example 2:

Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= nums.length
