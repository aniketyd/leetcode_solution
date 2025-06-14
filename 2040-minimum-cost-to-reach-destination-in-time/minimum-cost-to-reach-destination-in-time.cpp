class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        // build adjacency list: adj[u] = vector of {v, travel_time}
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }
        
        const int INF = 1e9;
        // fees[i] = min cost to reach i
        // times[i] = min time to reach i (under the cheapest cost path so far)
        vector<int> fees(n, INF), times(n, INF);
        fees[0] = passingFees[0];
        times[0] = 0;
        
        // min-heap of (cost so far, time so far, node)
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(fees[0], 0, 0);
        
        while (!pq.empty()) {
            auto [cost, time, u] = pq.top(); 
            pq.pop();
            // if we've already found a strictly better way to u, skip
            if (cost > fees[u] && time > times[u]) 
                continue;
            
            // try all outgoing edges
            for (auto& [v, wt] : adj[u]) {
                int newTime = time + wt;
                if (newTime > maxTime) 
                    continue;
                int newCost = cost + passingFees[v];
                
                // if we improve on cost or on time, we should revisit v
                if (newCost < fees[v] || newTime < times[v]) {
                    if (newCost < fees[v]) 
                        fees[v] = newCost;
                    if (newTime < times[v]) 
                        times[v] = newTime;
                    pq.emplace(newCost, newTime, v);
                }
            }
        }
        
        return (fees[n-1] < INF ? fees[n-1] : -1);
    }
};