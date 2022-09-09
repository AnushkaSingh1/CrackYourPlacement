class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        while(head)
        {
            v.push_back(head -> val);
            head = head -> next;
        }
        reverse(v.begin() + left - 1, v.begin() + right );
        for(auto i : v)
            cout << i << " ";
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        for(int i = 0 ; i < v.size(); i++)
        {
            temp -> next = new ListNode(v[i]);
            temp = temp -> next;
        }
        return dummy -> next;
    }
};


















92. Reverse Linked List II
Medium

7881

343

Add to List

Share
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?









