class Solution {
public:
    int ans = INT_MAX;
    vector<vector<int>> g;
    vector<int> depth;
    void dfs(int v, int parent, int d) {
        depth[v] = d;
        for (int u : g[v]) {
            if (u != parent) {
                if (depth[u] > d + 1) dfs(u, v, d + 1);
                else if (depth[u] < d) {
                    ans = min(ans, d-depth[u]+1);
                }
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        g.resize(n);
        depth.resize(n, INT_MAX);
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (int i=0; i<n; i++) {
            if (depth[i] == INT_MAX) dfs(i, -1, 0);
        }
        return ans==INT_MAX?-1:ans;
    }
};