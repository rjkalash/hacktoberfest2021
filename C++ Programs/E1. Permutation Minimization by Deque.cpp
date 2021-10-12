#include<bits/stdc++.h>
#define int 				long long
#define pb 					push_back
#define endl 				'\n'
#define ff 					first
#define ss 					second
#define vi 					vector<int>
#define pii 				pair<int, int>
#define all(x)				(x).begin(), (x).end()
#define rep(i, a, b)		for(int i=a; i<b; i++)
#define setbits(x) 			__builtin_popcountll(x)
#define FIO 				ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 				1e19
#define MAX 				100005
#define mod 				1000000007 // 1e9+7

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

using namespace std;

void solve() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	deque<int> q;
	for (int i = 0; i < n; i++) {
		if (q.size() == 0) {
			q.push_front(a[i]);
			continue;
		}

		if (a[i] > q.front()) {
			q.push_back(a[i]);
		} else if (a[i] < q.front()) {
			q.push_front(a[i]);
		} else {

			q.push_back(a[i]);

		}
	}

	while (q.size()) {
		cout << q.front() << " ";
		q.pop_front();
	} cout << endl;



}

signed main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FIO

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
