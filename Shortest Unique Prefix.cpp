/** question link: https://www.interviewbit.com/old/problems/shortest-unique-prefix/ **/

{
    int cnt;
    char val;
    int end;
    trie* child[26];
};

trie* root;
trie* newnode(int index)
{
    trie* curr = new trie;
    curr->val = 'a'+index;
    curr->cnt = 0;
    curr->end = 0;
    
    for(int i=0;i<26;i++)
        curr->child[i] = NULL;
    //cout<<1<<endl;
    return curr;
}
void create(string& s)
{
    trie* curr = root;
    int index;
    for(int i=0;i<s.size();i++)
    {
        index = s[i]-'a';
        if(!curr->child[index])
            curr->child[index] = newnode(index);
        curr->child[index]->cnt += 1;
        curr->child[index]->val = s[i];
        curr = curr->child[index];
    }
    curr->end += 1;
}

void search(string& s,vector<string>& ans)
{
    trie* curr = root;
    string ss = "";
    //cout<<s<<endl;
    for(int i=0;i<s.size();i++)
    {
        int index = s[i] - 'a';
        curr = curr->child[index];
        if(curr->cnt>1)
            ss += s[i];
            
        else
        {
            ss += s[i];
            break;
        }
    }
    ans.push_back(ss);
}
vector<string> Solution::prefix(vector<string> &A) 
{
    root = newnode('/' - 'a');
    for(int i=0;i<A.size();i++)
        create(A[i]);
    
    vector<string> ans;
    for(int i=0;i<A.size();i++)
        search(A[i],ans);
    
    //cout<<ans.size()<<endl;
    return ans;
}
