class Solution {
public:
   vector<int>dp;
    void dfs2(vector<vector<pair<int,int>>>&adj,int node,int parent){
            if(parent!=-1){
                int prevWt=0;
                for(auto &[adjNode,wt]:adj[node]){
                    if(adjNode==parent){
                        prevWt=wt;
                        break;
                    }
                }
                if(prevWt==0)
                dp[node]=dp[parent]-1;
                else
                dp[node]=dp[parent]+1;
            }
            for(auto &[adjNode,wt]:adj[node]){
                if(adjNode!=parent)
                dfs2(adj,adjNode,node);
            }
    }
    void dfs(vector<vector<pair<int,int>>>&adj,int node,int parent){
             int sum=0;
             for(auto &[adjNode,wt]:adj[node]){
                if(adjNode!=parent){
                    dfs(adj,adjNode,node);
                   sum+=wt+dp[adjNode];
                }
             }
             dp[node]=sum;
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n+1);
        int m=edges.size();
        dp.resize(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],0});
            adj[edges[i][1]].push_back({edges[i][0],1});
        }
        dfs(adj,0,-1);
        dfs2(adj,0,-1);
        return dp;
        
    }
};