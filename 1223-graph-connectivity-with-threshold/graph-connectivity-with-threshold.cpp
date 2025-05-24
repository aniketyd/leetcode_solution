class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    }
    int findParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int uPar=findParent(u);
        int vPar=findParent(v);
        if(uPar==vPar)return ;
        if(size[uPar]>size[vPar]){
            size[uPar]+=size[vPar];
            parent[vPar]=uPar;
        }
        else{
            size[vPar]+=size[uPar];
            parent[uPar]=vPar;
        }
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        if(n==0){
            vector<bool>v(true,queries.size());
            return v;
        }
        DSU ds(n+1);
        for(int i=threshold+1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                  ds.unionBySize(i,j);
            }
        }
        vector<bool>ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
             if(ds.findParent(queries[i][0])==ds.findParent(queries[i][1]))
             ans[i]=true;
        }
        return ans;
    }
};