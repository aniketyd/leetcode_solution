class Solution {
public:
int N,M;
   bool fun(vector<vector<int>>&grid,vector<vector<int>>&vis,int i , int j){

    vis[i][j]=1;
    if(i==N-1&&j==M-1)return true;
    if(grid[i][j]==0)return false;
    if(i+1<N&&vis[i+1][j]==0){
        grid[i][j]=0;
        if(fun(grid,vis,i+1,j))
        return true;
        grid[i][j]=1;
    }
     if(j+1<M&&vis[i][j+1]==0){
        grid[i][j]=0;
        if(fun(grid,vis,i,j+1))
        return true;
        grid[i][j]=1;
    }
    return false;

   }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        N=n;M=m;
        vector<vector<int>>vis(n,vector<int>(m)),v(n,vector<int>(m));
        if(fun(grid,vis,0,0)==false)return true;
        for(int i=1;i<m;i++)
        if(grid[0][i]==1)
        v[0][i]=1;
        else break;
        for(int i=1;i<n;i++)
        if(grid[i][0]==1)
        v[i][0]=1;
        else break;
        grid[0][0]=1;
       v[0][0]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==1)
                v[i][j]=v[i-1][j]|v[i][j-1];
            }
        }
        return !v[n-1][m-1];
    }
};