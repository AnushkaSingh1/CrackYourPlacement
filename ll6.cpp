ListNode* removeElements(ListNode* head, int val) {

    if(head==NULL) return NULL;
 
    head->next=removeElements(head->next,val);
    
    return head->val==val?head->next:head;
    
}








class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* copy = head;
        ListNode* temp = copy;
        while(copy!=NULL){
            if(head->val==val)
                head = head->next;
            if(copy->val==val){
                temp->next = copy->next;
                copy = copy->next;
                continue;
            }
            temp = copy;
            copy = copy->next;
        }
        return head;
    }
};















class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev=new ListNode(-1);  // make a dummy node (prev)
        prev->next=head;                  // join it to head   
        ListNode *cur=prev;               //make both cur and prev on first dummy node
        if(head==NULL) return NULL;       //if head Is null simply return it 
        
    while(cur!=NULL&&cur->next!=NULL)      
        {
        if(cur->next->val==val)           //check if value in cur->next is matching with key
         { 
            cur->next=(cur->next->next!=NULL)?cur->next->next:NULL; //if matching give it to cur->next else give null
         }
           
          else { cur=cur->next;}
      
        }
        
        return prev->next;  
    }
};
