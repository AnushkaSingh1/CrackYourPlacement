class Solution {
public: 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=0, len2=0; 
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        
        while(curr1){
            len1++;
            curr1 = curr1->next;
        }
        while(curr2){
            len2++;
            curr2 = curr2->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        curr1 = l1;
        curr2 = l2;
        
        while(len1 && len2){ // no carry 
            int sum =0;
            if(len1 > len2){
                sum+=curr1->val;
                len1--;
                curr1 = curr1->next;
            }else if(len1 < len2){
                sum+=curr2->val;
                len2--;
                curr2 = curr2->next;
            }else {
                sum +=curr1->val + curr2->val;
                len1--;
                len2--;
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            prev = new ListNode(sum);
            prev->next = curr;
            curr = prev;
        } // curr 
        
        prev = NULL;
        ListNode* head = NULL;
        
        int carry = 0;
        while(curr){
            int val = (curr->val+carry)%10;
            if(curr->val + carry>=10) carry=1;
            else carry=0;
            prev = new ListNode(val);
            prev->next = head;
            head = prev;
            curr = curr->next;
        }
        cout<<carry<<endl;
        if(carry!=0){
            prev = new ListNode(1);
            prev->next = head;
        }
        return prev;
    
    }
};



















445. Add Two Numbers II
Medium

3923

232

Add to List

Share
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?




