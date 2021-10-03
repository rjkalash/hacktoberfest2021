// Problem link - https://codeforces.com/contest/118/problem/A



#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a;
    int x = a.length();
    for(int i=0; i<x; i++){
        if(a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'y' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U' && a[i] != 'Y')
        {
            b = b + '.';
            b = b +  (char)tolower(a[i]);
        }
    }
    cout << b << endl;
    return 0;
}
