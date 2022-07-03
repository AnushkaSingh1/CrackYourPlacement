class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        unsigned long long int num=0,ite=0,tmp,revmult=1,reverse=0;
        while(temp!=NULL){
            tmp=temp->val;
            num=(10*num)+tmp;
            reverse=revmult*tmp+reverse;
            revmult*=10;
            //std::cout<<reverse<<std::endl;
            ite++;
            temp=temp->next;
        }
        if(num==reverse){
            return 1;
        }
        else{
            return 0;
        }
    }
};












class Solution {
ListNode* reverse(ListNode*head){
    
    ListNode*temp=head,*next,*prev=NULL;
    while(temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev; 
}
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL)return true;
        
        if(head->next==NULL)return true;
        
        if(head->next->next==NULL){
            return head->val==head->next->val;
        }
        
        ListNode*slow=head,*fast=head;
        
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverse(slow->next);
        slow=slow->next;
        fast=head;
        while(slow!=NULL){
            if(slow->val!=fast->val)return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};











bool isPalindrome(ListNode* head) {
        bool moveMidPtr = false;
        ListNode* h1 = nullptr;
        ListNode* h2 = head;
        ListNode* tmp = head;
        while(tmp) {
            tmp = tmp->next;
            if (moveMidPtr) {
                // remove the first element from the current list
                // and push front into the new list.
                ListNode* tmp2 = h2;
                h2 = h2->next;
                tmp2->next = h1;
                h1 = tmp2;
            }
            moveMidPtr = moveMidPtr ? false : true;
        }
        
        if (moveMidPtr) {
            h2 = h2->next;
        }
        
        // now compare 2 lists
        while(h1) {
            if (h1->val != h2->val) {
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }

        return true;
    }












Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9











