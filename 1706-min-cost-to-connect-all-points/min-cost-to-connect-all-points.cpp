class DSU{
    public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n+1);
       
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
   int findUlp(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUlp(parent[node]);
    }
    void unionB(int u,int v){
        int parU=findUlp(u);
        int parV=findUlp(v);
        if(parU==parV)return;
        parent[parU]=parV;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                 edges.push_back({dis,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        DSU ds(n+1);
        int Cost=0;
        for(int i=0;i<edges.size();i++){
             if(ds.findUlp(edges[i][1])==ds.findUlp(edges[i][2]))
             continue;
             Cost+=edges[i][0];

             ds.unionB(edges[i][1],edges[i][2]);
        }
        return Cost;
    }
};