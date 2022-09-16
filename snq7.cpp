class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> res;
        for(int i = 0; i < n; i++)
            res.push_back(0);
        int i = 1;
        stack <int> s;
        s.push(0);
        while(!s.empty()){
            if(i >= n){
                break;
            }
            if(temperatures[i] <= temperatures[s.top()]){
                s.push(i);
                i++;
            }
            else{
                res[s.top()] = i-s.top();
                s.pop();
                if(s.empty()){
                    s.push(i);
                    i++;
                }
            }
        }
        return res;
    }
};




















739. Daily Temperatures
Medium

8109

180

Add to List

Share
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100



