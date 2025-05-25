class Solution {
public:
   int ans=1e9;
  
    void dfs(vector<vector<int>>&adj,int node,vector<int>&visited){
        visited[node]=1;
       
       unordered_set<int>st;
        for(auto adjnd:adj[node]){
            if(visited[adjnd])continue;
            st.insert(adjnd);
        }
       ;
        for(auto nd:st){
            for(auto adjnd:adj[nd]){
                if(st.find(adjnd)!=st.end()){
                    int temp=adj[node].size()+adj[nd].size()+adj[adjnd].size();
                    ans=min(ans,temp-6);
                }
            }
        }
        

        for(auto adjnd:adj[node]){
            if(visited[adjnd]==0)
            dfs(adj,adjnd,visited);
        }
    }
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n+1);
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                dfs(adj,i,visited);
            }
        }
        if(ans>1e6)return -1;
        return ans;
    }
};