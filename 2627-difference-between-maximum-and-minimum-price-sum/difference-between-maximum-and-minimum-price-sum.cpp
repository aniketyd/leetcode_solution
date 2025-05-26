class Solution {
public:
#define ll long long
vector<long long>subTree;
vector<long long>dp;
  void dfs2(vector<vector<int>>&adj,int node,int parent,vector<int>&price){
      ll mx1=dp[node],mx2=0;
      for(auto adjNode:adj[node]){
        if(adjNode!=parent){
            if(subTree[adjNode]>mx1){
                mx2=mx1;
                mx1=subTree[adjNode];
            }
            else if(subTree[adjNode]>mx2)
            mx2=subTree[adjNode];
        }
      }
      dp[node]=mx1;
      for(auto adjNode:adj[node]){
        if(adjNode!=parent){
            if(subTree[adjNode]==mx1){
                dp[adjNode]=mx2+price[node];
                dfs2(adj,adjNode,node,price);
            }
            else{
                dp[adjNode]=mx1+price[node];
                dfs2(adj,adjNode,node,price);
            }
        }
      }
  }
  void dfs(vector<vector<int>>&adj,int node,int parent,vector<int>&price){
    subTree[node]=price[node];
    for(auto adjNode:adj[node]){
        if(adjNode!=parent){
           dfs(adj,adjNode,node,price);
            subTree[node]=max(subTree[node],price[node]+subTree[adjNode]);
        }
    }
  }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        subTree.resize(n+1);
        dp.resize(n+1);
        dfs(adj,0,-1,price);
        dfs2(adj,0,-1,price);
        long long mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,dp[i]);
           
        }
return mx;
    }
};