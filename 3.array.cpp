class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[j] = nums[i];
                count++;
                j++;
            }
        }
        return ++count;
    }
};






class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};







class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k=nums[0];
        int idx=1;
       for ( int i=1; i<nums.size(); i++)
       {
           if ( nums[i] != k)
           {
               nums[idx] = nums[i];
               idx++;
               k = nums[i];
           }

       }
        return idx;
    }
};
