class Solution {
public:
   vector<int> dijkstra(vector<vector<pair<int,int>>>&adj,int source,int n){
       vector<int>dis(n,1e9+10);
       dis[source]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,0});
       while(!pq.empty()){
             int crrdis=pq.top().first;
             int nd=pq.top().second;
             pq.pop();
             if(crrdis>dis[nd])continue;
             for(auto val:adj[nd]){
                if(crrdis+val.second<dis[val.first]){
                    dis[val.first]=crrdis+val.second;
                    pq.push({dis[val.first],val.first});
                }
             }
       }
       return dis;
   }
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        int m=edges.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]+1});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]+1});
        }
        vector<int>dis;
        dis=dijkstra(adj,0,n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(dis[i]<=maxMoves){
                ans++;
            }
        }
        for(int i=0;i<m;i++){
            int nd1=edges[i][0],nd2=edges[i][1],cnt=edges[i][2];
            int count=0;
            if(dis[nd1]!=(1e9+10)&&dis[nd1]<maxMoves){
               count+=min(cnt,maxMoves-dis[nd1]);
            }
            if(dis[nd2]!=(1e9+10)&&dis[nd2]<maxMoves){
                count+=min(cnt,maxMoves-dis[nd2]);
            }
            count=min(count,cnt);
            ans+=count;
        }
        return ans;
    }
};