// Longest Increasing Subsequence
//  I/P: 8 10 15 10 12 14 15   O/P: 5
// ----------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// lis bottom up O(n*n)
int bottomUp(int ar[], int n) {
	int * dp = new int[n];
	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (ar[j] < ar[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	return *max_element(dp, dp + n);
}

// lis O(NlogN)
int lis(int ar[], int n) {
	int len = 1;
	vector<int> v; // v[i] stores lis ending at i

	v.push_back(ar[0]);

	for (int i = 1; i < n; i++) {
		if (v[len - 1] < ar[i])v.push_back(ar[i]), len++;
		else {
			int idx = lower_bound(v.begin(), v.end(), ar[i]) - v.begin();
			v[idx] = ar[i];
		}
	}
	return len;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int * ar = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	cout << lis(ar, n) << '\n';

	delete []ar;

	return 0;

}