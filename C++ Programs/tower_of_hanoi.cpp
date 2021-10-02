#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void solve(int start, int dest, int help, int n)
    {
        if (n == 1)
        {
            cout << "Moving plate " << n << " from " << start << " to " << dest << endl;
            return;
        }
        solve(start, help, dest, n - 1);
        cout << "Moving plate " << n << " from " << start << " to " << dest << endl;
        solve(help, dest, start, n - 1);
    }
    vector<int> shiftPile(int N, int n)
    {
        int start = 1;
        int help = 2;
        int dest = 3;
        solve(start, dest, help, n);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, n;
        cin >> N >> n;

        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// Input: N = 2, n = 2
// Output: 1 3
// Explaination:  The plate on top of box 1 is
// first transferred to box 2. The second plate
// from box 1 is transferred to box 3 and finally
// the plate from box 2 is transferred to box 3.
// In each situation, all the constraints are
// satisfied. You are required to print the 2nd
// move which is "Move plate from box 1 to box 3",
// hence 1 3.