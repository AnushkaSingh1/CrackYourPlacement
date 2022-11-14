class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        
        stack <int>st;
        int area=0;
        
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int h=heights[st.top()];
                st.pop();
                
                if(st.empty()){
                    area=max(area,h*i);
                }
                else{
                    int l=i-st.top()-1;
                    area=max(area,h*l);
                }
            }
            st.push(i);
        }
        return area;
    }
};















84. Largest Rectangle in Histogram
Hard

12608

176

Add to List

Share
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
