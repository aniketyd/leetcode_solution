class Solution {
public:
    vector<long long> dikjstra(vector<vector<pair<int,int>>>&adj,int source,int n){
        vector<long long>distance(n,1e10);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        distance[source]=0;
        pq.push({0,source});
        while(!pq.empty()){
            long long currDis=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();
            if(currDis>distance[currNode])continue;
            for(auto &[adjNode,wt]:adj[currNode]){
                if(distance[adjNode]>(currDis+wt)){
                    pq.push({currDis+wt,adjNode});
                    distance[adjNode]=currDis+wt;
                }
            }
        }
        return distance;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
          vector<vector<pair<int,int>>>adj(n);
          int m=edges.size();
          for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});  
          }
         vector<long long>disA= dikjstra(adj,0,n);
         vector<long long>disB= dikjstra(adj,n-1,n);
         int ans=disA[n-1];
         vector<bool>arr(m,false);
         if(ans==1e10)return arr;
         for(int i=0;i<m;i++){
            if(ans==(disA[edges[i][0]]+disB[edges[i][1]]+edges[i][2])||ans==(disA[edges[i][1]]+disB[edges[i][0]]+edges[i][2]))
            arr[i]=true;
         }
         return arr;
    }
};