class Solution {
public:
vector<int>pS,lvl;
vector<vector<int>>dp;
    void dfs(vector<vector<pair<int,int>>>&adj,int node,int parent,int prefixSum,int level){
          pS[node]=prefixSum;
          lvl[node]=level;
          if(parent!=-1){
          dp[node][0]=parent;
          for(int i=1;i<21;i++){
             dp[node][i]=dp[dp[node][i-1]][i-1];
          }
          }
          for(auto &[adjNode,wt]:adj[node]){
            if(adjNode!=parent){
                prefixSum+=wt;
                dfs(adj,adjNode,node,prefixSum,level+1);
                prefixSum-=wt;
            }
          }
    }
    int lca(int node1,int node2){
        if(node1==node2)return node1;
        if(lvl[node1]<lvl[node2])swap(node1,node2);
        int levelDiff=lvl[node1]-lvl[node2];
        int equalNode=node1;
        for(int i=0;i<21;i++){
            if((1<<i)&levelDiff)
            equalNode=dp[equalNode][i];
        }
        node1=equalNode;
        if(node1==node2)return node1;
        for(int i=20;i>=0;i--){
            if(dp[node1][i]==dp[node2][i])continue;
            node1=dp[node1][i];
            node2=dp[node2][i];
        }
        return dp[node1][0];
    }
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        vector<vector<pair<int,int>>>adj(n+1);
       
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        pS.resize(n);
        lvl.resize(n);
        dp.resize(n,vector<int>(22,0));
        dfs(adj,0,-1,0,0);
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int src1=queries[i][0];
            int src2=queries[i][1];
            int dest=queries[i][2];
            int lca1=lca(src1,src2);
            int lca2=lca(src2,dest);
            int lca3=lca(src1,dest);
           
            long long sum=pS[src1]+pS[src2]-2*pS[lca1];
            sum+=pS[src2]+pS[dest]-2*pS[lca2];
            sum+=pS[src1]+pS[dest]-2*pS[lca3];
            ans.push_back(sum/2);

        }
        return ans;

    }
};