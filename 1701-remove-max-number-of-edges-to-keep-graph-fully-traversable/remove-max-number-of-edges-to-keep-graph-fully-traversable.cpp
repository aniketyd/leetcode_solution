class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
      parent.resize(n+1);
      size.resize(n+1);
      for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
      }
    }
      int findUlp(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUlp(parent[node]);
      }
      void unionBySize(int u,int v){
        int uPar=findUlp(u);
        int vPar=findUlp(v);
        if(uPar==vPar)return;
        if(size[uPar]>size[vPar]){
            size[uPar]+=size[vPar];
            parent[vPar]=uPar;
        }else{
            size[vPar]+=size[uPar];
            parent[uPar]=vPar;
        }
      }
    };


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        int count =0;
        DSU ds1(n+1),ds2(n+1);
        for(int i=0;i<m;i++){
              if(edges[i][0]==3){
                if(ds1.findUlp(edges[i][1])==ds1.findUlp(edges[i][2])){
                    count++;continue;
                }
                ds1.unionBySize(edges[i][1],edges[i][2]);
                ds2.unionBySize(edges[i][1],edges[i][2]);
              }
        }
        for(int i=0;i<m;i++){
            if(edges[i][0]==1){
                if(ds1.findUlp(edges[i][1])==ds1.findUlp(edges[i][2])){
                    count++;continue;
                }
                ds1.unionBySize(edges[i][1],edges[i][2]);
            }
        }
         for(int i=0;i<m;i++){
            if(edges[i][0]==2){
                if(ds2.findUlp(edges[i][1])==ds2.findUlp(edges[i][2])){
                    count++;continue;
                }
                ds2.unionBySize(edges[i][1],edges[i][2]);
            }
        }
        if(ds1.size[ds1.findUlp(1)]!=n||ds2.size[ds2.findUlp(1)]!=n)return -1;
        return count;
    }
};