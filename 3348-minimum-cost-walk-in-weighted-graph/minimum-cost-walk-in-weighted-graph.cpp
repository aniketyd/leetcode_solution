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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int m=edges.size();
        DisjointSet d(n);
        vector<int>v(n+1,INT_MAX);
        for(int i=0;i<m;i++){
            int par1=d.findUPar(edges[i][0]);
            int par2=d.findUPar(edges[i][1]);
            d.unionByRank(edges[i][0],edges[i][1]);
            int fpar=d.findUPar(edges[i][0]);
            v[fpar]=v[par1]&v[par2]&edges[i][2];
        }
        int q=query.size();
        vector<int>ans;
        for(int i=0;i<q;i++){
            int par1=d.findUPar(query[i][0]);
            int par2=d.findUPar(query[i][1]);
            if(par1!=par2)
            ans.push_back(-1);
            else{
                ans.push_back(v[par1]);
            }
        }
        return ans;
    }
};