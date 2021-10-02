// problem link - https://codeforces.com/contest/71/problem/A


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        int x = s.length();
        if(x<=10){
            cout << s << endl;
        }
        else{
            cout << s[0] << x-2 << s[x-1] << endl;
        }
    }
    return 0;
}
