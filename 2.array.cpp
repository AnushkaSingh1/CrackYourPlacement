class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt0++;
            else if(nums[i]==1)cnt1++;
            else cnt2++;
        }
        int i=0;
        while(cnt0--){
            nums[i++]=0;
        }
        while(cnt1--){
            nums[i++]=1;
        }
        while(cnt2--){
            nums[i++]=2;
        }
    }
};




class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map <int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(map[0]!=0)
              {  nums[i]=0;
               map[0]--;
              }
            
            else if(map[1]!=0)
               { nums[i]=1;
                              map[1]--;
}
            else
                {nums[i]=2;
                               map[2]--;
}
        }
    }
};
