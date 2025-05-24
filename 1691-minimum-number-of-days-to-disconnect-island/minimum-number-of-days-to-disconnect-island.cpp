class Solution {
public:
   void bfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int x,int y){
    visited[x][y]=1;
    int n=grid.size();
        int m=grid[0].size();
    queue<pair<int,int>>q;
    q.push({x,y});
    int adjx[4]={0,1,0,-1};
    int adjy[4]={1,0,-1,0};
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nwx=i+adjx[k];
            int nwy=j+adjy[k];
            if(nwx>=0&&nwy>=0&&nwx<n&&nwy<m&&!visited[nwx][nwy]&&grid[nwx][nwy])
            {
                q.push({nwx,nwy});
                visited[nwx][nwy]=1;
            }
        }

    }
   }
    int applyingBfs(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0&&grid[i][j]){
                    bfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int result=applyingBfs(grid);
        if(result>1||result==0)return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    result=applyingBfs(grid);
                    grid[i][j]=1;
                    if(result>1||result==0)return 1;
                }
            }
        }
        return 2;
    }
};