#include <bits/stdc++.h>
using namespace std;

void permu(string str, int i, int n)
{
    int j;
    if (i == n)
    {
        cout << str << endl;
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((str[i]), (str[j]));
            permu(str, i + 1, n);
            swap((str[i]), (str[j]));
        }
    }
}

int main()
{
    string str_original;
    cout << "Enter a String: ";
    cin >> str_original;
    cout << "Entered string has following permutations: " << endl;
    permu(str_original, 0, str_original.length() - 1);
    return 0;
}