class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;
            q.push(i);
            dist[i] = 0;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        parent[neighbor] = node;
                        q.push(neighbor);
                    } else if (parent[node] != neighbor) {
                        // Found a cycle
                        ans = min(ans, dist[node] + dist[neighbor] + 1);
                    }
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
