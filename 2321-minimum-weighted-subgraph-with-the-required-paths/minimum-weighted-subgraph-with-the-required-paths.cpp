class Solution {
public:
#define ll long long
    vector<ll> dijkstra(vector<vector<pair<int,int>>>&adj,int source,int n){
        vector<ll>distance(n+1,1e15);
        distance[source]=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0LL,source});
        while(!pq.empty()){
               ll curDis=pq.top().first;
               ll curNode=pq.top().second;
               pq.pop();
               if(distance[curNode]<curDis)continue;
               for(auto &[adjNode,weight]:adj[curNode]){
                if(distance[adjNode]>(distance[curNode]+weight)){
                    distance[adjNode]=distance[curNode]+weight;
                    pq.push({distance[adjNode],adjNode});
                }
               }
        }
        return distance;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>>adj(n+1),revAdj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            revAdj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<ll>dis1=dijkstra(adj,src1,n);
        vector<ll>dis2=dijkstra(adj,src2,n);
        vector<ll>disDest=dijkstra(revAdj,dest,n);
        ll minWeight=1e15;
        for(int i=0;i<n;i++){
            minWeight=min(minWeight,dis1[i]+dis2[i]+disDest[i]);
        }
        if(minWeight>1e12)return -1;
        return minWeight;

    }
};