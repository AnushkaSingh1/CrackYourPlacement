class Solution {
    // static bool comp(vector<int> &a, vector<int> &b)
    // {
    //     if(a[0]==b[0])
    //         return a > b;
    //     return a < b;
    // }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int ans = 0, val = intervals[0][1];
        for(int i = 1; i < n; i++)
        {
            if(val <= intervals[i][0])
            {
                val = intervals[i][1];
            }
            else if(val <= intervals[i][1])
            {
                ans++;
                //val = intervals[i][1];
            }
            else if(val > intervals[i][1])
            {
                ans++;
                val = intervals[i][1];
            }
        }
        return ans;
    }
};
