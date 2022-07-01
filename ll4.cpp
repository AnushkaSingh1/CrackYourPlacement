class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* ans = new ListNode(-1);
		ListNode* curr = ans;
		if(head == NULL)return NULL;

		while(head->next != NULL){
			if(head->next && head->val != head->next->val){
				curr->next = new ListNode(head->val);
				curr = curr->next;
			}
			head = head->next;
		}

		if(curr->val != head->val){
			curr->next = new ListNode(head->val);
			curr = curr->next;
		}

		return ans->next;
	}
};









class Solution {
public:
ListNode* deleteDuplicates(ListNode* head) {
if(head==NULL || head->next==NULL){
return head;
}

    ListNode* nextHead=deleteDuplicates(head->next);
    
    if(head->val==nextHead->val)return nextHead;
    else{
        
        head->next=nextHead;
        return head;
    }
}
};












ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        if(head->next && head->next->val == head->val){
            return this->deleteDuplicates(head->next);
        }
        head->next = this->deleteDuplicates(head->next);
        return head;
    }















Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.


