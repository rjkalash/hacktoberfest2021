// Question Link - https://codeforces.com/contest/1579/problem/B


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >>tc;
    while(tc--){
        string str;
        cin >>str;
        int p = str.length();
        long long int x=0,y=0,z=0;
        for(int i=0; i<p; i++){
            if(str[i] == 'A'){
                x++;
            }
            if(str[i] == 'B'){
                y++;
            }
            if(str[i] == 'C'){
                z++;
            }
        }
        if(x+z == y){
            cout <<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
