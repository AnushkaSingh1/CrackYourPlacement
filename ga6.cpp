class Solution {
public:
   
    int minCost(string colors, vector<int>& needTime) {
        int ans=0;
       for(int i=0;i<colors.size()-1;i++){
           if(colors[i]!=colors[i+1]) continue;
           else{
               if(needTime[i]>needTime[i+1]) swap(needTime[i],needTime[i+1]);
               ans+=min(needTime[i],needTime[i+1]);
           }
       }
        return ans;
    }
};
