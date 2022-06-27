Method 1 - Hashset
Time Complexity - O(n)
Space Complexity -  O(n)
int missingNumber(vector<int>& nums) {
	unordered_set<int> m(nums.begin(),nums.end());
    for(int i=0 ; i < nums.size()+1 ; ++i){
        if(!m.count(i)) return i;
    }
    return 0;
}
Method 2 - Sorting
Time Complexity - O(nlogn)
Space Complexity -  O(1)
int missingNumber(vector<int>& nums) {
	sort(nums.begin(),nums.end());
    for(int i=0 ; i < nums.size() ; ++i){
        if(i != nums[i]) return i;
    }
    return nums.size();
}
Method 3 - Binary Search
Time Complexity - O(nlogn)
Space Complexity -  O(1)
int missingNumber(vector<int>& nums) {
	sort(nums.begin(),nums.end());
    int low = 0;
    int high = nums.size();
    
    while(low < high){
        int mid = (low + high)/2;
        if(nums[mid] > mid){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
Method 4 - Sum of n natural number
Time Complexity - O(n)
Space Complexity -  O(1)
int missingNumber(vector<int>& nums) {
	int n = nums.size();
    int nsum = n*(n+1)/2,sum = 0;
    for(int i=0 ; i < n ; ++i){
        sum += nums[i];
    }
    return nsum - sum;
}
Method 5 - XOR
Time Complexity - O(n)
Space Complexity -  O(1)
int missingNumber(vector<int>& nums) {
	int res = nums.size();
    for(int i=0 ; i < nums.size() ; ++i){
        res ^= nums[i] ^ i;
    }
    return res;
}
