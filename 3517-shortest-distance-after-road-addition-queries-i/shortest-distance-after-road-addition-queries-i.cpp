class Solution {
public:

    int dijkstra(int V, vector<vector<pair<int,int>>> &adj, int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int w = it.second;
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    pq.push({dis + w, v});
                }
            }
        }
        return distTo[V-1];
    }


    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>ans;
        for(int i=0;i<n-1;i++){
             adj[i].push_back({i+1,1});
            
        }
        for(int i=0;i<queries.size();i++){
            adj[queries[i][0]].push_back({queries[i][1],1});
            
            ans.push_back(dijkstra(n,adj,0)); 
        }
        return ans;
    }
};