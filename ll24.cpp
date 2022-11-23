class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		//edge cases
        if (head == NULL || k ==0 ||k==1)return head;
		// Store all node values in a vector.
        vector<int> v;
        ListNode* p = head;
        while(p){
            v.push_back(p->val);
            p = p->next;
        }
        int n = v.size();
		// r is how many sub groups are to be reversed; 
        int r = n/k;
        int q = 0;
		// Apply operations on the vector i.e, swap values in a loop. 
        while(r--){
            int i = k*q;
            int j = (k)*(q+1) - 1;
            while(i<j){
                swap(v[i++], v[j--]);
            }
            q++;
        }
		// Make a new LinkedList by the processed vector and return it.
        ListNode* a = new ListNode(v[0]);
        ListNode* b = a;
        for(int i =1; i<v.size(); i++){
            b->next = new ListNode(v[i]);
            b = b->next;
        }
        return a;
    }
};






















25. Reverse Nodes in k-Group
Hard

9698

552

Add to List

Share
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?




