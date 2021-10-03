#include<bits/stdc++.h>
using namespace std;

void solve(string str,string sol,vector<string> &soltuion)
{
    if(str.length()==0)
    {
        soltuion.push_back(sol);
        return;
    }
    string temp1=sol;
    string temp2=sol;
    temp2+=str[0];
    str.erase(str.begin()+0);
    solve(str,temp1,soltuion);
    solve(str,temp2,soltuion);
}
int main(){
    string str;
    cin>>str;
    vector<string> sol;
    solve(str,"",sol);
    for(auto a: sol)
    cout<<a<<endl;
    return 0;
}