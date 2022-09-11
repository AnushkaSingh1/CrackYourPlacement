class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* first = head;
        ListNode* second = head;
        
       
        for(int i=0;i<n;i++)
        {
            if(first!=NULL)
                first = first->next;
           
        }
        
        ListNode* prev;
        
        if(!first) 
            return head->next;
        
        
        while(first!=NULL){
            prev = second;
            first = first->next;
            second = second->next;
        }
        
        ListNode* temp = second;
        prev->next = second->next;
        delete temp;
        
        return head;
        
    }
};

















19. Remove Nth Node From End of List
Medium

12288

534

Add to List

Share
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?




