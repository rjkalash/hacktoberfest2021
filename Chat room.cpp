// problem link - https://codeforces.com/contest/58/problem/A


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    string b = "hello";
    int j = 0, count = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i] == b[j]){
            j++;
            count++;
            if(count == 5){
                break;
            }
        }
    }
    if(j==5){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
