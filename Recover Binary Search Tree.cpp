/** Question link: https://www.interviewbit.com/problems/recover-binary-search-tree/ 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* A) {
 
 
int mx=INT_MIN,mn=INT_MAX;
TreeNode *curr=A;
while(curr!=NULL){
    if(curr->left==NULL){
        if(mn==INT_MAX){
                if(mx<curr->val)mx=curr->val;
                else mn=curr->val;
            }
            else mn=min(mn,curr->val);
        curr=curr->right;
    }
    else{
        TreeNode *tmp=curr->left;
        while(tmp->right!=NULL&&tmp->right!=curr){
            tmp=tmp->right;
        }
        if(tmp->right==NULL){
            tmp->right=curr;
            curr=curr->left;
        }
        else{
            tmp->right=NULL;
            if(mn==INT_MAX){
                if(mx<curr->val)mx=curr->val;
                else mn=curr->val;
            }
            else mn=min(mn,curr->val);
            curr=curr->right;
        }
    }
}
return {mn,mx};
}
