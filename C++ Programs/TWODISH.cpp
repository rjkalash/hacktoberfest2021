#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, A, B, C;
    cin >> T;
    while (T--)
    {
        cin >> N >> A >> B >> C;
        if (B < N)
        {
            cout << "NO\n";
        }
        else if (A + C < N)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}
