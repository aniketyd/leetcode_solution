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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        DisjointSet ds(n);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<pairs.size();i++){
            ds.unionByRank(pairs[i][0],pairs[i][1]);
        }
        for(int i=0;i<n;i++){
            mp[ds.findUPar(i)].push_back(i);
        }
        for(auto &val:mp){
            vector<int>v=val.second;
            string temp="";
            for(int i=0;i<v.size();i++){
               temp+=s[v[i]];
            }
            sort(temp.begin(),temp.end());
            for(int i=0;i<v.size();i++)
             s[v[i]]=temp[i];
        }
        return s;
    }
};