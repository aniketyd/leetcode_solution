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
int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& as) {
        int n=s.size();
        DisjointSet ds(n);
        for(int i=0;i<as.size();i++){
            ds.unionByRank(as[i][0],as[i][1]);
        }
        unordered_map<int,multiset<int>>mp;
        for(int i=0;i<n;i++){
            mp[ds.findUPar(i)].insert(s[i]);
        }
        int c=0;
        for(int i=0;i<n;i++){
          auto it=  mp[ds.findUPar(i)].find(t[i]);
          if(it!=mp[ds.findUPar(i)].end()){
            mp[ds.findUPar(i)].erase(it);
            c++;
          }
        }
        return n-c;
    }
};