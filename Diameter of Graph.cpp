// Question link - https://codeforces.com/contest/1581/problem/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        if(b > a*(a-1) /2 || b < a-1){
            cout << "NO" << "\n";
        }
        else if(a==1 && c<=1){
            cout << "NO" << "\n";
        }
        else if(a==2 && c<=2){
            cout << "NO" << "\n";
        }
        else if(a >=3 && (b < a-1 || b < a*(a-1)/2 && c<=3 || b >= a*(a-1)/2 && c <= 2)){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }
    }
    return 0;
}
