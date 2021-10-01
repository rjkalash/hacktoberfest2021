/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *ans = new ListNode(0);
    ListNode *res = ans;
    if(A==NULL){return B;}
    if(B==NULL){return A;}
    while(A!=NULL && B!=NULL){
        if(B->val>A->val){
            res->next = new ListNode(A->val);
        }
        else if(B->val<=A->val){
            res->next = new ListNode(B->val);
        }
        A = A->next;
        B = B->next;
        res = res->next;
    }
    if(A!=NULL){
        res->next = A;
    }
    if(B!=NULL){
        res->next = B;
    }
    return ans->next;
}

