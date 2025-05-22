class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        int mod=1e9+7;
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0LL,0});
        vector<long long>dis(n,1e18);
        dis[0]=0LL;
        vector<int>np(n,0);
        np[0]=1;
        int c=0;
        while(!pq.empty())
        {
            long long crtm=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            if(crtm>dis[node])continue;
            for(auto val:adj[node])
            {
                long long d=crtm+val.second;
               
                if((d)==dis[val.first])
                {
                   np[val.first]=(np[val.first]+np[node])%mod;

                }
               else if((d)<dis[val.first])
                {
                    np[val.first]=np[node]%mod;
                    dis[val.first]=d;
                    pq.push({d,val.first});
                }
               
            }
        }
     
        return np[n-1];

    }
};