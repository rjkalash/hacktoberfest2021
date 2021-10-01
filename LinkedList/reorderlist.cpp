/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
reorderList(ListNode* A) {
    ListNode *slow = A;
    ListNode *fast = slow->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *curr = A;
    ListNode *currev = slow->next;
    slow->next = NULL;

    ListNode *prevv = NULL;
    ListNode *cn = currev;
    ListNode *nextt = NULL;
    while(cn!=NULL){
        nextt = cn->next;
        cn->next = prevv;
        prevv=cn;
        cn = nextt;
    }

    ListNode *res = new ListNode(0);
    ListNode *ans = res;
    while(curr!=NULL || prevv!=NULL ){
        if(curr){
            ans->next = curr;
            curr = curr->next;
            ans = ans->next;
        }
        if(prevv){
            ans->next = prevv;
            prevv = prevv->next;
            ans = ans->next;
        }
    }
    return res->next;
}

