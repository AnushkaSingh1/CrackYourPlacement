class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n1 = INT_MIN, n2 = INT_MIN, n3 = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= n1){
                n3 = n2;
                n2 = n1;
                n1 = nums[i];
            }
            else if(nums[i] < n1 and nums[i] >= n2){
                n3 = n2;
                n2 = nums[i];
            }
            else if(nums[i] < n2 and nums[i] >= n3){
                n3 = nums[i];
            }
        }
        
        int m1 = INT_MAX, m2 = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= m1){
                m2 = m1;
                m1 = nums[i];
            }
            else if(nums[i] > m1 and nums[i] <= m2){
                m2 = nums[i];
            }
        }
        return max(n1*n2*n3,m1*m2*n1);
    }
};














class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int x = nums[n-2]*nums[n-1]*nums[n-3];
        int y = nums[0]*nums[1]*nums[n-1];
        
        return max(x,y);
    }
};









Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:
