class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        for(auto i:lists)
        {
            while(i!=NULL)
            {
                v.push_back(i->val);
                i=i->next;
            }
        }
        ListNode* head=new ListNode;
        ListNode* temp=head;
        sort(v.begin(),v.end());
        for(auto i:v)
        {
            ListNode* st=new ListNode(i);
            temp->next=st;
            temp=temp->next;
        }
        return head->next;
    }
};



















23. Merge k Sorted Lists
Hard

14839

558

Add to List

Share
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104
