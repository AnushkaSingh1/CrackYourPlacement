class Solution {
public:
    int Merge(vector < int > & nums, int low, int mid, int high) {
      int total = 0;
      int j = mid + 1;
      for (int i = low; i <= mid; i++) {
        while (j <= high && nums[i] > 2*(long long) nums[j]) {
          j++;
        }
        total += (j - (mid + 1));
      }
    
      vector < int > t;
      int left = low, right = mid + 1;
    
      while (left <= mid && right <= high) {
    
        if (nums[left] <= nums[right]) {
          t.push_back(nums[left++]);
        } else {
          t.push_back(nums[right++]);
        }
      }
    
      while (left <= mid) {
        t.push_back(nums[left++]);
      }
      while (right <= high) {
        t.push_back(nums[right++]);
      }
    
      for (int i = low; i <= high; i++) {
        nums[i] = t[i - low];
      }
      return total;
    }
    int MergeSort(vector < int > & nums, int low, int high) {
    
      if (low >= high) return 0;
      int mid = (low + high) / 2;
      int inv = 0;
      inv += MergeSort(nums, low, mid);
      inv += MergeSort(nums, mid + 1, high);
      inv += Merge(nums, low, mid, high);
      return inv;
    }

    int reversePairs(vector<int>& nums) {
        return MergeSort(nums, 0, nums.size() - 1);
    }
};



















493. Reverse Pairs
Hard

3726

199

Add to List

Share
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1


