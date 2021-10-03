#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        if (N % 4 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            int rem = N % 4;
            if (rem % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
