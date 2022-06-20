class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos;
        vector<int> output(2);
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (pos.find(complement) != pos.end())
            {
                output[0] = pos[complement];
                output[1] = i;
                return output;
            }
            pos[nums[i]] = i;
        }
        
        return vector<int>(2, -1);
    }
};
