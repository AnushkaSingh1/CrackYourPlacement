class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, maxH = 0;
        stack<int>stk, idx;
        for(int i = 0; i < height.size(); i++){
            int h = min(maxH, height[i]);
            if(!stk.empty()){
                int temp = 0, preIdx = i, preH = h, curH = h;
                while(!stk.empty() && stk.top() < height[i]){
                    curH = stk.top();
                    temp += (h - preH) * (preIdx - idx.top()) - (curH - preH);
                    preH = stk.top();
                    stk.pop();
                    preIdx = idx.top();
                    idx.pop();
                }
                if(!stk.empty()) temp += (h - preH) * (preIdx - 1 - idx.top());
                sum += temp;
            }
            stk.push(height[i]);
            idx.push(i);
            maxH = max(maxH, height[i]);
        }
        return sum;
    }
};
















42. Trapping Rain Water
Hard
24.2K
337
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105










