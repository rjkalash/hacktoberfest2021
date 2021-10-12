/*---------------------------------------Header Files---------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

/*---------------------------------------MACROS---------------------------------------*/

#define times_run           	long long ___tc=1; cin >> ___tc; while (___tc--	)
#define rep(i,x,y)				for(int i=x;i<y;i++)

#define pb 						push_back
#define pf 						push_front

#define	nl						cout<<"\n";

/*---------------------------------------Input/Output---------------------------------------*/

void start_func()
{	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

/*---------------------------------------Main Code---------------------------------------*/

void chalochale()
{
	int n,node;
	cin>>n>>node;
    
    deque<int> dq;
    dq.push_back(node);
    rep(i, 1, n)
    {
        cin >> node;
        if (node > dq[0])
        {
            dq.pb(node);
        }
        else
        {
            dq.pf(node);
        }
    }
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
}

int32_t main()
{
	start_func();
	times_run
	{
		chalochale();
		nl
	}
	return 0;
}