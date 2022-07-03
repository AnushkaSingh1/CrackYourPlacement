class Solution {
public:
    ListNode* reverseList(ListNode* head);
};
/****************************************************************/
ListNode* Solution::reverseList(ListNode* head) {
    vector<int> auxV;
    ListNode *auxP = head;
    int i;
    size_t size;
    while (auxP != nullptr) {
        auxV.emplace_back(auxP->val);
        auxP = auxP->next;
    }
    size = auxV.size();
    auxP = head;
    for (i = size-1; i >= 0; --i) { 
        auxP->val = auxV[i];
        auxP = auxP->next;
    }
    return head;
}











class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* A = nullptr;
        ListNode* B = head;
        ListNode* C = head?head->next:nullptr;
        while(B != nullptr) {
            B->next = A;
            A = B;
            B = C;
            if(C!=nullptr)C = C->next;
        }
        return A;
    }
};












class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next)return head;
        
        ListNode* h = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        return h;
    }
};










Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000











