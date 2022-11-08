class NumArray {
public:
    
    vector<int> tree;
    
    void rangeUpdate (int lo, int hi, int ind, int si, int dif) {
        if (ind < lo or ind > hi) {
            return ;
        }
        tree[si] += dif;
        if (lo != hi) {
            int md = lo + (hi - lo) / 2;
            rangeUpdate(lo, md, ind, 2 * si + 1, dif);
            rangeUpdate(md + 1, hi, ind, 2 * si + 2, dif);
        }
    } 
    
    int rangeSum (int lft, int rgt, int lo, int hi, int si) {
        if (lft <= lo and rgt >= hi) {
            return tree[si];
        } 
        if(hi < lft or lo > rgt) {
            return 0;
        }
        int md = lo + (hi - lo) / 2;
        return rangeSum(lft, rgt, lo, md, 2 * si + 1) + rangeSum(lft, rgt, md + 1, hi, 2 * si + 2);
    }
    
    int build (vector<int> & vec, int lo, int hi, int si) {
        if (lo == hi) {
            return tree[si] = vec[lo];
        }
        int md = lo + (hi - lo) / 2;
        return tree[si] = build(vec, lo, md, 2 * si + 1) + build(vec, md + 1, hi, 2 * si + 2);
    }
    
    NumArray (vector<int>& vec) {
        tree.resize(4 * vec.size(), 0);
        build(vec, 0, vec.size() - 1, 0);
    }
    
    void update (int ind, int val) {
        rangeUpdate(0, tree.size() / 4 - 1, ind, 0, val - sumRange(ind, ind));
    }
    
    int sumRange (int lft, int rgt) {
        return rangeSum(lft, rgt, 0, tree.size() / 4 - 1, 0);
    }
};



















307. Range Sum Query - Mutable
Medium

4128

225

Add to List

Share
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.




















