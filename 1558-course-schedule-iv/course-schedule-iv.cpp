class Solution {
public:
   void dfs(int node, vector<vector<int>>&adj,vector<int>&vis,int src, vector<vector<int>>&mp){
    vis[node]=1;
    mp[src][node]=1;
    for(auto val:adj[node]){
        if(vis[val]==0)
        dfs(val,adj,vis,src,mp);
    }
   }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
       vector<vector<int>>mp(n,vector<int>(n));
       for(int i=0;i<n;i++){
        vector<int>vis(n);
        dfs(i,adj,vis,i,mp);
       }
       vector<bool>ans;
       for(int i=0;i<q.size();i++){
        if(mp[q[i][1]][q[i][0]])
        ans.push_back(true);
        else
        ans.push_back(false);
       }
return ans;
    }
};