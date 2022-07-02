ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    Unordered_set<ListNode*>st;
    st.clear();
    
    while(headA!=NULL){
        st.insert(headA);
        headA=headA->next;
    }
    
    while(headB!=NULL){
       if(st.find(headB)!=st.end()){
           return headB;
       }
        
        headB=headB->next;
        
    }
    
    return NULL;
    
    
}
TC-O(2*N). Assuming that the hash set table take O(1) time to access.
SC-O(N) to store in set

Optimal sol:-

TC-O(2*N),SC:-O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    ListNode* A=headA;
    ListNode* B=headB;
    
    while(A!=NULL || B!=NULL){
        
        if(A==B) return A;
        
        A=A->next;
        B=B->next;
        
        if(A==NULL && B!=NULL)
            A=headB;
        if(B==NULL && A!=NULL)
            B=headA;
    
    }
    return NULL;
}


















int length(ListNode *h){
    int c=0;
    while(h!=NULL){
        c++;
        h=h->next;
    }
    return c;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    int l1=length(headA);  //length of LL1
    int l2=length(headB);  //length of LL2
    
    ListNode *temp, *c1=NULL, *c2=NULL;  //c1 and c2 are respective pointers for LL's
    int diff;                            //temp will travel the LL until (l1-l2) or (l2-l1)
    
    if(l1>=l2){    //if LL1 is bigger
        diff=l1-l2;
        temp = headA;  //temp will travel until l1-l2
        c2=headB;      //c2 is fixed
    }
    else{         //if LL2 is bigger
        diff=l2-l1;
        temp=headB;   //temp will travel unitl (l2-l1)
        c1=headA;     //c1 is fixed
    }
    
    for(int i=0;i<diff;i++){  //temp is updated
        temp=temp->next;
    }
    
    if(c2==NULL) c2=temp;
    else if(c1==NULL) c1=temp;
    
    while(c1!=NULL && c2!=NULL){  //now c1 and c2 are the head's of both LL and traverse 
        if(c1==c2){               //simulataneously until both point to same node
            return c1;
        }
        c1=c1->next;
        c2=c2->next;
    }
    
    return NULL;
}














class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set <ListNode*> hash;
        
        ListNode* curr=headA;
        while(curr){
            hash.insert(curr);
            curr = curr->next;
        }
        
        curr=headB;
        while(curr){
            if(hash.find(curr) != hash.end())
                return curr;
            curr= curr->next;
        }
        
        return curr;
    }
};




