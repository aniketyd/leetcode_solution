class Solution {
public:
    vector<pair<int,int>>dp;
    void dfs(vector<vector<int>>&adj,int node,int parent){
        int mx=0,mx2=0;
        for(auto adjNode:adj[node]){
            if(adjNode!=parent){
                dfs(adj,adjNode,node);
                int val;
                if(adjNode%2==0)
                val=dp[adjNode].first+2;
                else
                val=dp[adjNode].first+1;
                if(val>mx){
                    mx2=mx;
                    mx=val;
                }
                else if(val>mx2){
                    mx2=val;
                }
            }
        }
        dp[node]={mx,mx2};
    }
        void dfs2(vector<vector<int>>&adj,int node,int parent){
        int mx=0;
        if(node!=0){
            if((dp[parent].first-(1+(node+1)%2))==dp[node].first){
                mx=dp[parent].second+1+((parent+1)%2);
            }
            else
              mx=dp[parent].first+1+((parent+1)%2);
        }
        if(dp[node].first<mx){
            dp[node]={mx,dp[node].first};
        }
        else if(dp[node].second<mx){
            dp[node]={dp[node].first,mx};
        }
        for(auto adjNode:adj[node]){
               if(adjNode!=parent){
                dfs2(adj,adjNode,node);
               }
        }
       
    }
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dp.resize(n);
        dfs(adj,0,-1);
        dfs2(adj,0,-1);
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(dp[i].first);
        }
        return ans;

    }
};