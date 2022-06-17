class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
       

        for(int sptr=0,fptr=0;fptr<nums.size();fptr++)  if(nums[fptr]!=0) swap(nums[sptr++],nums[fptr]);   
         
        
        // we increment the fptr and sptr simultaneously untill we get zero
        // when we encounter zero sptr will lag behind fptr and it will swapp with next non zero fptr
        
        
        // while( fptr++<nums.size()) 
        // {
        //     if(nums[fptr]!=0) {swap(nums[sptr++],nums[fptr]);   
        //        
        // }
        
    }
};
