//  STRONGLY CONNECTED COMPONENT
//--------------------------------
//      KOSARAJU ALGORITHM
// -------------------------------

#include <bits/stdc++.h>
using namespace std;


void dfs1(vector<int>g[], bool vis[], int src, stack<int>& st) {
	vis[src] = true;
	for (auto nbrs : g[src]) {
		if (!vis[nbrs])dfs1(g, vis, nbrs, st);
	}
	st.push(src);
}

void dfs2(vector<int>reverse_g[], bool vis[], int src) {
	vis[src] = true;
	cout << src << " ";
	for (auto nbrs : reverse_g[src]) {
		if (!vis[nbrs])dfs2(reverse_g, vis, nbrs);
	}
}

void kosaraju(vector<int>g[], vector<int>reverse_g[], int V) {

	bool vis[V] = {0};
	// step 1 - store the vertices in decreasing order of finish time
	stack<int> st;

	for (int i = 0; i < V; i++) {
		if (!vis[i])dfs1(g, vis, i, st);
	}

	// step 2 - reverse the edges of the graph

	// step 3 - dfs according to ordering in stack
	memset(vis, 0, sizeof vis);
	while (!st.empty()) {
		int node = st.top();
		st.pop();
		if (!vis[node]) {
			cout << "Component -> ";
			dfs2(reverse_g, vis, node);
			cout << '\n';
		}
	}
}


int main() {

	int n, m; // n vertices m edges
	cin >> n >> m;

	vector<int> g[n];
	vector<int> reverse_g[n];

	while (m--) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		reverse_g[y].push_back(x);
	}

	kosaraju(g, reverse_g, n);

	return 0;
}