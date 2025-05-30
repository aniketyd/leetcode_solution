class Solution {
public:
    void dfs(vector<vector<int>>&adj,int source,vector<int>&ans,int level,int parent,vector<int>&vis){
        vis[source]=1;
        ans[source]=level;
        for(auto adjNode:adj[source]){
            if(vis[adjNode]==0){
                dfs(adj,adjNode,ans,level+1,source,vis);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        vector<int>ans1(n+1,1e9),ans2(n+1,1e9),vis1(n+1),vis2(n+1);
        dfs(adj,node1,ans1,0,-1,vis1);
        dfs(adj,node2,ans2,0,-1,vis2);
        int minDist=1e9;
        int node;
       
        for(int i=0;i<n;i++){
           if((max(ans1[i],ans2[i]))<minDist){
            minDist=max(ans1[i],ans2[i]);
            node=i;
           }
        }
        if(minDist>1e6)
return -1;
  return node;
    }
};