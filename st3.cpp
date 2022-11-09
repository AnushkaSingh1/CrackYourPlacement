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
    }
};
