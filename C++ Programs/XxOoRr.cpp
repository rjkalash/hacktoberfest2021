//problem link - https://www.codechef.com/JULY21C/problems/XXOORR


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int answer;
    int m, k;
    while(T--)
    {
        cin >> m >> k;
        vector<int> a(m);

        for(int& i : a)
        {
            cin >> i;
        }

        vector<int> nSetBit(32);
        int count;
        int term;

        for(int bit=0; bit<=30; bit++)
        {
            count = 0;
            for(int& i : a){
                if(i%2!=0){
                    count++;
                }
                i = i/2;
            }
            nSetBit[bit] = count;
        }

        answer = 0;

        for(int bit=0; bit<=30; bit++)
        {
            if(nSetBit[bit]%k == 0){
                answer += nSetBit[bit]/k;
            }
            else
            {
                answer += nSetBit[bit]/k + 1;
            }
        }

        cout << answer << endl;

    }
    return 0;
}
