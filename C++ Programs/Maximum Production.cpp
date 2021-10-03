//problem link - https://www.codechef.com/JULY21C/problems/EITA


#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli a, b, c;
    cin >> a;
    while(a--){
        //lli d, x, y, z;
        lli d, x, y, z;
        cin >> d >> x >> y >> z;
        lli c1 = 7*x;
        lli c2 = y*d + (7-d)*z;
        lli r = max(c1, c2);
        cout << r <<"\n";
    }
    return 0;
}
