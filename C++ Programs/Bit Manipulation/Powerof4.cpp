#include <bits/stdc++.h>
using namespace std;

bool ispowerof4(int n)
{
     if (n == 1)
          return true;

     bool singleBit = (n & (n - 1)) == 0;
     bool lastDigit = n % 10 == 4 || n % 10 == 6;

     return singleBit && lastDigit;
}

int main()
{
     cout << ispowerof4(8) << endl;
     return 0;
}
