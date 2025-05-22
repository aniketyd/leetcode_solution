class Solution {
public:
   int N;
   vector<int>subtreeNodes,distanceSum;
   void dfs1(vector<vector<int>>&adj,int node,int parent){
       for(auto adjNode:adj[node]){
        if(adjNode!=parent){
            dfs1(adj,adjNode,node);
            subtreeNodes[node]+=subtreeNodes[adjNode];
            distanceSum[node]+=distanceSum[adjNode]+subtreeNodes[adjNode];
                    }
       }
       subtreeNodes[node]+=1;
   }
   void dfs2(vector<vector<int>>&adj,int node,int parent){
          if(parent!=-1){
            distanceSum[node]=distanceSum[parent]+N-2*subtreeNodes[node];
          }
          for(auto adjNode:adj[node]){
              if(adjNode!=parent){
                dfs2(adj,adjNode,node);
              }
          }
   }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        N=n;
        vector<vector<int>>adj(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        subtreeNodes.resize(n);
        distanceSum.resize(n);
        dfs1(adj,0,-1);
        dfs2(adj,0,-1);
        return distanceSum;
    }
};