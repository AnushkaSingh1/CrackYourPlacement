class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* a1=NULL, *a2=NULL, *a3=a1, *a4=a2, *t=head;
        if(!head || !head->next) return head;
        while(t)
        {
            if(t->val<x)
            {
                if(a1==NULL){
                    a1=t;
                    a3=a1;
                }
                else
                {
                    a1->next=t;
                    a1=a1->next;
                }
            }
            else
            {
                if(a2==NULL){
                    a2=t;
                    a4=a2;
                }
                else
                {
                    a2->next=t;
                    a2=a2->next;
                }
            }
            
            t=t->next;
        }
        
        if(a1)
            a1->next = NULL;
        if(a2)
            a2->next = NULL;
        if(a3==NULL){
            return a4;
        }
        else
        {
            a1->next = a4;
        }
        return a3;
    }
};



















86. Partition List
Medium

4782

575

Add to List

Share
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
