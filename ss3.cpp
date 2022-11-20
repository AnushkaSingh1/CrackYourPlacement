class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        
        while (l <= r) {
            int mid = l + (r-l)/2;
            int midElem = nums[mid];
            
            if (midElem == target) {
                return mid;
            }
            
            int leftElem = nums[l];
            int rightElem = nums[r];
           
            if (leftElem == target) { // Similar to check above
                return l;
            } else if (rightElem == target) {
                return r;
            }
            
            if (midElem < rightElem) { // Soft inquiry to the right portion of mid
                if (midElem < target && target <= rightElem) { // Intial inquiry was correct! & this portion is not rotated
                    l = mid + 1;
                } else { // Upon further examination, we'll look into the left portion of mid instead
                    r = mid - 1;
                }
                   
            } else { // Soft inquiry to the left portion of mid
                if (midElem > target && target >= leftElem) { // Inquiry was correct! We'll further investigate the left portion of mid & this portion is not rotated
                    r = mid - 1;
                } else { // Initial inquiry was incorrect, instead we will investigate the right portion of mid
                    l = mid + 1;
                }
            }
        } 
        return -1;
    }
};






















33. Search in Rotated Sorted Array
Medium

18620

1108

Add to List

Share
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104



