
#include <iostream>
using namespace std;
 
// Returns number of ways
// to reach s'th stair
int countWays(int n, int m)
{
    int res[n + 1];
    int temp = 0;
    res[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int s = i - m - 1;
        int e = i - 1;
        if (s >= 0)
        {
            temp -= res[s];
        }
        temp += res[e];
        res[i] = temp;
    }
    return res[n];
}
 
// Driver Code
int main()
{
    int n = 5, m = 3;
    cout << "Number of ways = "
         << countWays(n, m);
    return 0;
}
 
