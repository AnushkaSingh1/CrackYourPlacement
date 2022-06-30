class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        ListNode* temp=head;
        while(temp!=NULL){
            ans=2*ans;
            ans=ans+(temp->val); // ans= ans+ temp ka data * 2 ki power 0 
            temp=temp->next;
        }
        return ans;
    }
};












class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    int getDecimalValue(ListNode* head) {
        ListNode* root = reverseList(head);
        
        int sum = 0;
        int i=0;
        while(root != NULL)
        {
            
            if(root->val == 1)
                sum += pow(2,i);
            i++;
            root = root->next;
        }
        return sum;
    }
};



















Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
