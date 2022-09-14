class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return MergeSort(head, nullptr);
    }
    
private:
    ListNode* MergeSort(ListNode* head, ListNode* END)
    {
        if (head == END)
            return head;
        
        if (head->next == END)
        {
            head->next = nullptr;
            return head;
        }
        
        ListNode *mid = head, *fast = head;
        while (fast != END && fast->next != END)
            mid = mid->next, fast = fast->next->next;
        
        ListNode* left = MergeSort(head, mid);
        ListNode* right = MergeSort(mid, END);
        
        return Merge(left, right);
    }
    
    ListNode* Merge(ListNode* left, ListNode* right)
    {
        ListNode *sorted = nullptr, *tail = nullptr;
        
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                if (sorted == nullptr)
                    sorted = tail = left;
                
                else
                    tail->next = left, tail = tail->next;
                
                left = left->next;
                tail->next = nullptr;
            }
            
            else
            {
                if (sorted == nullptr)
                    sorted = tail = right;
                
                else
                    tail->next = right, tail = tail->next;;
                
                right = right->next;
                tail->next = nullptr;
            }
        }
        
        if (left != nullptr)
            tail->next = left;
        
        else
            tail->next = right;
        
        return sorted;
    }
};


















148. Sort List
Medium

8182

251

Add to List

Share
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?


