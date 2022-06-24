class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min=nums[0],n=nums.size(),cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]<min){
                min=nums[i];
            }
        }
        for(int i=0;i<n;i++){
            cnt=cnt+(nums[i]-min);
        }
        return cnt;
    }
};
