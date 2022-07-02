class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        if (list1->val < list2->val) {list1->next = mergeTwoLists(list1->next, list2); return list1;}
        else {list2->next = mergeTwoLists(list1, list2->next); return list2;}
    }
};













class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        while( !(list1 == nullptr && list2 == nullptr)) {
            if(list1 == nullptr || list2 == nullptr) {
                ListNode* remain= list1==nullptr?list2:list1;
                head->next = remain;
                break;
            } else {
                ListNode* next_head = list1->val < list2->val?list1:list2;
                if(next_head==list1) {
                    list1 = list1->next;
                } else {
                    list2 = list2->next;
                }
                head->next = next_head;
                next_head->next = nullptr;
                head = head->next;
            }
        }
        return ans->next;
    }
};

















ListNode* append(ListNode *head,int element ){
        ListNode *temp=head;
        if(head==NULL){
            ListNode *temp1=new ListNode(element);
            head=temp1;
        }
        else{
            while(temp->next!=NULL){
                   temp=temp->next;
            }
            ListNode *temp1=new ListNode(element);
            temp->next=temp1;
        }
        
        
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=NULL;
        //IN this we are going to use simple merge sort Logic 
        ListNode *temp1=list1;
        ListNode *temp2=list2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                head=append(head,temp1->val);
                temp1=temp1->next;
            }
            else{
                head=append(head,temp2->val);
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            head=append(head,temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            head=append(head,temp2->val);
            temp2=temp2->next;
        }
        return head;
    }


















class Solution {
public:
    ListNode* Merge(ListNode* list1, ListNode* list2){
        if(list1->next==NULL){
            list1->next=list2;
            return list1;
        }
        ListNode* curr1=list1;
        ListNode* next1=list1->next;
        ListNode* curr2=list2;
        
        while(next1!=NULL && curr2!=NULL){
            if(curr2->val >= curr1->val && curr2->val <= next1->val){
                curr1->next=curr2;
                ListNode* next2=curr2->next;
                curr2->next=next1;
                curr1=curr1->next;
                curr2=next2;
            }
            else{
                curr1=next1;
                next1=next1->next;
                if(next1==NULL){
                    curr1->next=curr2;
                    return list1;
                }
            }
        }
          return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        if(list1->val < list2->val){
           return Merge(list1,list2);
        }
        
        return Merge(list2,list1);
    }
};














You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.















