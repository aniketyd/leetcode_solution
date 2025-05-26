class Solution {
public:
   unordered_map<int,unordered_map<int,int>>dp;
   int dfs(vector<vector<int>>&adj,vector<int>&coins,int node,int parent,int k,int level){
        if(level>14)return 0;
        if(dp[node].find(level)!=dp[node].end())return dp[node][level];
        int sum=coins[node];
        int l=level;
        while(sum>0&&l>0){
            sum/=2;
            l--;
        }
        int result1=sum/2;
        int result2=sum-k;
        for(auto adjNode:adj[node]){
            if(adjNode!=parent){
                result1+= dfs(adj,coins,adjNode,node,k,level+1);
                result2+=dfs(adj,coins,adjNode,node,k,level);
            }
        }
        return dp[node][level]=max(result1,result2);
        
   }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int m=edges.size();
        int n=m+1;
       vector<vector<int>>adj(n+1); 
       for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
       }
    return   dfs(adj,coins,0,-1,k,0);
    

    }
};