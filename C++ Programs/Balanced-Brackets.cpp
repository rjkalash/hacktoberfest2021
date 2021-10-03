#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    
    stack<char>st;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.size()==0||st.top()!='(')
            {
                cout<<"false"<<endl;
                return 0;
            }
            else
            st.pop();
        }
        else if(s[i]=='}')
        {
            if(st.size()==0||st.top()!='{')
            {
                cout<<"false"<<endl;
                return 0;
            }
            else
            st.pop();
            
        }
        else if(s[i]==']')
        {
            if(st.size()==0||st.top()!='[')
            {
                cout<<"false"<<endl;
                return 0;
            }
            else
            st.pop();
        }
    }
    if(st.empty())
    cout<<"true"<<endl;
    else
    
    cout<<"false"<<endl;
    }
