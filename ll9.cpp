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














Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
Example 2:


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Constraints:

The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
1 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA < m
0 <= skipB < n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
 




