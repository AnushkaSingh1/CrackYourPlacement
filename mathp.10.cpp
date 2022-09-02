class Solution {
public:
    int sd(vector<int>p1,vector<int>p2){
        return pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1],2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int sd0,sd1,sd2,sd3;
        vector<vector<int>>pts={p1,p2,p3,p4};
        sort(begin(pts),end(pts));
        sd0=sd(pts[0],pts[1]);
        sd1=sd(pts[0],pts[2]);
        sd2=sd(pts[0],pts[3]);
        sd3=sd(pts[1],pts[2]);
        return sd0 && sd2 && sd0==sd1 && sd2==sd3;
    }
};










593. Valid Square
Medium

772

803

Add to List

Share
Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

 

Example 1:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true
Example 2:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false
Example 3:

Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true
 

Constraints:

p1.length == p2.length == p3.length == p4.length == 2
-104 <= xi, yi <= 104


