// question link - https://codeforces.com/contest/1579/problem/B

#include<bits/stdc++.h>
#define int long long int
#define pb push_back
using namespace std;
#define N 1000000007
#define PI 3.141592653589793238462
int mod_add(int x, int y, int z)
{
    x = x % z; 
    y = y % z; 
    return (((x + y) % z) + z) % z;
}
 
int mod_mul(int x, int y, int z)
{
    x = x % z;
    y = y % z;
    return (((x * y) % z) + z) % z;
}
 
int mod_sub(int x, int y, int z)
{
    x = x % z;
    y = y % z;
    return (((x - y) % z) + z) % z;
}
 
signed main(){
 
	int i,j,k,num,tc;
	cin>>tc;
	while(tc--)
	{
		cin>>num;
		vector<int> vect(num);
		vector<int> fact(num);
		for(i=0;i<num;i++)
		{
			cin>>vect[i];
			fact[i] = vect[i];
		}
		sort(fact.begin(),fact.end());
		vector< pair<pair<int,int> , int> > astra;
		for(i=0;i<num;i++)
		{
			for(j=i;j<num;j++)
			{
				if(vect[j] == fact[i])
				{
					vect[j] = -10000000000000000;
					break;
				}
			}
			if(i != j)
			{
				astra.push_back({{i+1,j+1},j-i});
			    for(k=j ;k>i ; k--)
				{
					vect[k] = vect[k-1];
				}
				vect[i] = -10000000000000000;
			}
		}
		cout<<astra.size()<<"\n";
		if(astra.size() > 0)
		{
			for(int i=0;i<astra.size();i++)
			{
				cout<<astra[i].first.first<<" "<<astra[i].first.second<<" "<<astra[i].second<<"\n";
			}
		}
	}
    return 0;
}
