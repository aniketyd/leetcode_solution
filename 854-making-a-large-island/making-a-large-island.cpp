class Solution {
public:
void dfs(vector<vector<int>>&grid,vector<vector<int>>&par,int node,int y,int c,int &sz){
    int n=grid.size();
    int m=grid[0].size();
    par[node][y]=c;
    sz++;
    int adx[4]={1,0,-1,0};
    int ady[4]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int x=node+adx[k];
        int yy=y+ady[k];
        if(x>=0&&yy>=0&&x<n&&yy<m&&par[x][yy]==-1&&grid[x][yy]==1)
        dfs(grid,par,x,yy,c,sz);
    }
}
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>par(n,vector<int>(m,-1));
        int c=1;
        unordered_map<int,int>mp;
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(par[i][j]==-1&&grid[i][j]==1){
                    int sz=0;
                    dfs(grid,par,i,j,c,sz);
                    mp[c]=sz;
                    
                    mx=max(mx,sz);
                    c++;
                }
            }
        }c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){c++;
                    int adx[4]={1,0,-1,0};
    int ady[4]={0,1,0,-1};
    set<int>s;
                   for(int k=0;k<4;k++){
                    int x1=i+adx[k];
                    int y1=j+ady[k];
                if((x1>=0&&x1<n&&y1>=0&&y1<m)&&(grid[x1][y1]==1)){ 
                      s.insert(par[x1][y1]);
                    }
                   }
                   int ss=0;
                   for(auto val:s){
                    ss+=mp[val];
                   }
                   mx=max(mx,ss);
                }
            }
        }
        if(c>0)mx++;
        return mx;
    }
};