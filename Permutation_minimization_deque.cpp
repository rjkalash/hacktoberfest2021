#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n;
        deque<int> d;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (d.empty() || a < d[0])
                d.push_front(a);
            else
                d.push_back(a);
        }
        for (int x : d)
            cout << x << ' ';
        cout << '\n';
    }
}
