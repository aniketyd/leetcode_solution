class Solution {
public:
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
    int bfs(int node,vector<vector<int>>&adj,int n){
        queue<int>q;
        q.push(node);
        vector<int>vis(n+1),grp(n+1,-1);
        int c=1;
        grp[node]=1;
        while(!q.empty()){
           int s=q.size();
           c++;
           for(int i=0;i<s;i++){
               int crn=q.front();
               q.pop();
               for(auto nn:adj[crn]){
                if(grp[nn]!=-1){
                    if(abs(grp[crn]-grp[nn])!=1)
                    return -1;
                }
               }
               for(auto nn:adj[crn]){
                if(grp[nn]==-1){
                    q.push(nn);
                    grp[nn]=c;
                }
               }
           }
        }
    
        return c-1;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        DisjointSet ds(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            ds.unionByRank(edges[i][0],edges[i][1]);
        }
        vector<int>ans(n+1);
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++){
           ans[i]=bfs(i,adj,n);
        }
        for(int i=1;i<=n;i++){
            mp[ds.findUPar(i)]=max(mp[ds.findUPar(i)],ans[i]);
        }
       
        int sum=0;
        for(auto val:mp){
            if(val.second==0)return -1;
          sum+=val.second;
        }
       return sum; 
    }
};