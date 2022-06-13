class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        for (int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if (nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
        
        // Restore numbers
        for (auto& num : nums)
            num = abs(num);
        
        return duplicate;
    }
};




class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map <int,int> dup;
        for(int i=0;i<nums.size();i++){
            dup[nums[i]]++;
            if(dup[nums[i]]>1)
                return nums[i];
        }
            return -1;

    }
};
