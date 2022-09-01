class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2){
            return n;
        }
        int res=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int>mp;
            int dup=0;
            double slope=0.00;
            for(int j=0;j<n;j++)
            {
                int x1=points[i][0];
                int x2=points[j][0];
                int y1=points[i][1];
                int y2=points[j][1];
                
                int dy=y2-y1;
                int dx=x2-x1;
                
                if(dy==0 && dx==0){
                    dup++;
                    continue;
                }
                if(dx!=0){
                    slope=dy*1.0/dx;
                }
                else{
                    slope=INT_MAX;
                }
                mp[slope]++;
            }
            if(mp.size()==0){
                res=dup;
            }
            else{
                for(auto slope:mp){
                    res=max(res,slope.second+dup);
                }
            }
        }
        return res;
    }
};

















149. Max Points on a Line
Hard

1464

230

Add to List

Share
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.




