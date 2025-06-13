class Solution {
public:
    int ans=0;
    int dfs(vector<vector<int>>&adj,int k,int node,int parent,vector<int>&values){
        int sum=values[node]%k;
        for(auto adjNode:adj[node]){
            if(adjNode!=parent){
               sum=(sum+ dfs(adj,k,adjNode,node,values))%k;
            }
        }
        if(sum==0)ans++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++)
       { 
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(adj,k,0,-1,values);
        return ans;
        
    }
};