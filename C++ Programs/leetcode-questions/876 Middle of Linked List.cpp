/* 
SUBMITTED BY: Deadeye001
DATE: 12/10/21
   */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* first=head;
        ListNode* second=head;
        while(second && second->next)
        {
            first=first->next;
            second=second->next->next;
        }
        return first;
    }
};
