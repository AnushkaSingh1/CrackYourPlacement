class Solution {
public:
    
    map<int, int> nxge;
    
    void next_greater(vector<int> &arr){
        stack<int> stk;
        
        int l = arr.size();
        for(int i = 0 ; i<l ; i++){
            
            if( stk.empty() || arr[stk.top()]>arr[i]){
                stk.push(i);
            }else{
                
                while( !stk.empty() && arr[stk.top()] < arr[i]){
                    
                    nxge[arr[stk.top()]] = arr[i];
                    
                    stk.pop();
                }
                stk.push(i);
            }
        }
        
        while(!stk.empty()){
            nxge[ arr[stk.top()] ] = -1;
            stk.pop();
        }
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        next_greater(nums2);
        
        for(int i = 0 ; i<nums1.size() ; i++){
            
            ans.push_back(nxge[nums1[i]]);
        }
        
        return ans;
    }
};















class Solution {
public:
    
    map<int, int> nxge;
    
    void next_greater(vector<int> &arr){
        stack<int> stk;
        
        int l = arr.size();
        for(int i = 0 ; i<l ; i++){
            
            if( stk.empty() || arr[stk.top()]>arr[i]){
                stk.push(i);
            }else{
                
                while( !stk.empty() && arr[stk.top()] < arr[i]){
                    
                    nxge[arr[stk.top()]] = arr[i];
                    
                    stk.pop();
                }
                stk.push(i);
            }
        }
        
        while(!stk.empty()){
            nxge[ arr[stk.top()] ] = -1;
            stk.pop();
        }
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        next_greater(nums2);
        
        for(int i = 0 ; i<nums1.size() ; i++){
            
            ans.push_back(nxge[nums1[i]]);
        }
        
        return ans;
    }
};














class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      for(int i=0;i<nums1.size();i++)
      {
          //find index of nums1[i] in nums2 array
            vector<int>::iterator it=find(nums2.begin(),nums2.end(),nums1[i]);
          //traverse from that index to end of nums2 array
            while(it!=nums2.end())
              {
                //if next greater element found 
                  if(*it> nums1[i])
                  { 
                      //add that to i th index in array
                        nums1[i] = *it;
                        break;
                  }
                  it++;
              } 
          //if not found ,then add -1
            if(it==nums2.end())
                nums1[i] = -1;
      }   
      return nums1;  
    }
};













The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.






















