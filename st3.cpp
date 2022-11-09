class Solution {
private:
    int node[4 * 20002], up_value = 10001;
    void update(int pos, int l = 1, int r = 20002, int root = 1) {
        if(pos < l || r < pos) return;
        if(l == r) {
            node[root]++;
            return;
        }

        int mid = (l + r) / 2;
        update(pos, l, mid, root * 2);
        update(pos, mid + 1, r, root * 2 + 1);

        node[root] = node[root * 2] + node[root * 2 + 1];
    }

    int query(int v, int l = 1, int r = 20002, int root = 1) {
        if(v < l || r < 1) return 0;
        if(1 <= l && r <= v) return node[root];

        int mid = (l + r) / 2;
        return query(v, l, mid, root * 2) + query(v, mid + 1, r, root * 2 + 1);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0; --i) {
            int x = nums[i] + up_value;
            update(x);
            ans.push_back(query(x - 1));
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        315. Count of Smaller Numbers After Self
Hard

7657

208

Add to List

Share
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
Accepted
280,855
Submissions
655,912
Seen this question in a real interview before?

Yes

No
    }
};
