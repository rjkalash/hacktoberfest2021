// Question Link - https://codeforces.com/contest/1579/problem/D


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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i,number,arsa;
	cin>>arsa;
	while(arsa--)
	{
		cin>>number;
		vector<int> vect(number);
		multiset< pair<int,int>> soln;
		for(int i=0;i<number;i++)
		{
			cin>>vect[i];
			if(vect[i] != 0)
			soln.insert({vect[i],i+1});
		}
		vector< pair<int,int> > answer;
		while(soln.size() > 1)
		{
			auto x = *soln.rbegin();
			auto y = *soln.begin();
			if(x.second == y.second)break;
			answer.push_back({x.second,y.second});
			soln.erase(soln.find(y));
			if(y.first - 1 != 0)
			{
				soln.insert({y.first-1,y.second});
			}
			soln.erase(soln.find(x));
			if(x.first - 1 != 0)
			{
				soln.insert({x.first-1,x.second});
			}
 
		}
		cout<<answer.size()<<"\n";
		for(int i=0;i<answer.size();i++)cout<<answer[i].first<<" "<<answer[i].second<<"\n";
	}
}
