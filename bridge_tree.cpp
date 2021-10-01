struct BridgeTree{
    vector<int> tin, low, compID;
    vector<bool> vis, isBridge;
    int n, m, timer, N;//N is count of 2-edge components
    void init(int _n, int _m) {
        n = _n, m = _m, timer = 0, N = -1;
        tin.resize(n), low.resize(n), vis.resize(n), isBridge.resize(m), compID.resize(n);
    }
    void dfs(int i, const vector<vector<pair<int, int>>> &g, int par = -1) {
        vis[i] = true;
        low[i] = tin[i] = timer++;
        for (auto [j, id]: g[i]) {
            if (j == par) continue;
            if (vis[j]) {
                low[i] = min(low[i], tin[j]);
            }else{
                dfs(j, g, i);
                low[i] = min(low[i], low[j]);
                if (low[j] > tin[i]) {
                    isBridge[id] = true;
                }
            }
        }
    }
    //Works in O(V + E)
    void extraChecks(const vector<vector<pair<int, int>>> &g) {
        vector<int> used(n);
        for (int i = 0; i < n; ++i) {
            for (auto [j, id]: g[i]) {
                used[j]++;
            }
            for (auto [j, id]: g[i]) {
                if (used[j] > 1) isBridge[id] = false;
            }
            for (auto [j, id]: g[i]) {
                used[j] = 0;
            }
        }
    }
    //Warning: All the below methods assumes that the graph is simple
    //Call extra checks if that's not the case
    void findBridges(const vector<vector<pair<int, int>>> &g) {
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) dfs(i, g);
        }
//        extraChecks(g);
    }
    void dfs1(int i, int curID, const vector<vector<pair<int, int>>> &g) {
        vis[i] = true;
        compID[i] = curID;
        for (auto [j, id]: g[i]) {
            if (isBridge[id] || vis[j]) continue;
            dfs1(j, curID, g);
        }
    }
    //Call this after finding bridges
    //Returns the number of vertices in bridge tree(Number of 2-edge connected components) and assigns IDS to vertices
    int find2EdgeConnectedComponents(const vector<vector<pair<int, int>>> &g) {
        vis.assign(n, false);
        int curID = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs1(i, curID, g);
                curID++;
            }
        }
        return N = curID;
    }
    //Returns the 2-edge connected components
    vector<vector<int>> getComponents(const vector<vector<pair<int, int>>> &g) {
        if (N == -1) {
            find2EdgeConnectedComponents(g);
        }
        vector<vector<int>> comps(N);
        for (int i = 0; i < n; ++i) {
            comps[compID[i]].push_back(i);
        }
        return comps;
    }
    //Returns the Bridge tree based on components without edge ID
    vector<vector<int>> buildBridgeTree(const vector<vector<pair<int, int>>> &g) {
        if (N == -1) {
            find2EdgeConnectedComponents(g);
        }
        vector<vector<int>> tree(N);
        for (int i = 0; i < n; ++i) {
            for (auto [j, id]: g[i]) {
                if (compID[i] != compID[j]) {
                    tree[compID[i]].push_back(compID[j]);
                }
            }
        }
        return tree;
    }
};
