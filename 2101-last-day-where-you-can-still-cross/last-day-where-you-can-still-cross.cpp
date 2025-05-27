class DSU{
    public:
    vector<int>parent;
    DSU(int n,int m){
      parent.resize(n*m+2);
      for(int i=0;i<n*m+2;i++){
         parent[i]=i;
      }
    }
    int findParent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node]);
    }
    void Union(int u,int v){
        parent[findParent(u)]=findParent(v);
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU ds(row,col);
        vector<vector<int>>field(row,vector<int>(col,1));
        int adjx[4]={0,1,-1,0};
        int adjy[4]={-1,0,0,1};
        for(int i=row*col-1;i>=0;i--){
            int x=cells[i][0]-1;
            int y=cells[i][1]-1;
            field[x][y]=0;
            for(int k=0;k<4;k++){
                int nx=x+adjx[k];
                int ny=y+adjy[k];
                if(nx>=0&&ny>=0&&nx<row&&ny<col&&field[nx][ny]==0){
                 ds.Union((x)*col+y,nx*col+ny);
                }
            }
            if(x==0)ds.Union(x*col+y,row*col);
            if(x==row-1)ds.Union(x*col+y,row*col+1);
            if(ds.findParent(row*col)==ds.findParent(row*col+1))return i;
        }
        return 0;
    }
};