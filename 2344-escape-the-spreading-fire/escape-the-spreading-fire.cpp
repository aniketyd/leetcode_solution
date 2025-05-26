class Solution {
public:
    const int MAXI=1e9;
    int maximumMinutes(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>fireDistance(n,vector<int>(m,MAXI));
        vector<vector<int>>manDistance(n,vector<int>(m,MAXI));
        // lets first spread fire
        queue<int>fire;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fireDistance[i][j]=0;
                    fire.push(i*m+j);
                }
            }
        }
        vector<int>dx={0,1,0,-1};
        vector<int>dy={1,0,-1,0};
        while(!fire.empty()){
            int node=fire.front();
            fire.pop();
            int i=node/m,j=node%m;
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<m && grid[i][j]!=2 && fireDistance[x][y]==MAXI){
                        fireDistance[x][y]=fireDistance[i][j]+1;
                        fire.push(x*m+y);
                }
            }
        }
        queue<int>man;
        manDistance[0][0]=0;
        man.push(0);
        while(!man.empty()){
            int node=man.front();
            man.pop();
            int i=node/m,j=node%m;
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<m && grid[i][j]!=2 && manDistance[x][y]==MAXI){
                        manDistance[x][y]=manDistance[i][j]+1;
                        man.push(x*m+y);
                }
            }
        }
        if(manDistance[n-1][m-1]==MAXI)
            return -1;
        if(fireDistance[n-1][m-1]==MAXI)
            return 1e9;
        // we will encounter two cases here,
        // 1. when fire and man both took same path
        // 2. when take different path
        int diff=fireDistance[n-1][m-1]-manDistance[n-1][m-1];
        bool flag=false;
        if(manDistance[n-1][m-2]+1==manDistance[n-1][m-1]){
            if(fireDistance[n-1][m-2]-manDistance[n-1][m-2]>diff)
                flag=flag||true;
        }
        if(manDistance[n-2][m-1]+1==manDistance[n-1][m-1]){
            if(fireDistance[n-2][m-1]-manDistance[n-1][m-2]>diff)
                flag=flag||true;
        }
        if(!flag)
            diff--;
        if(diff>=0)
            return diff;
        return -1;
        // TC: O(N*M+N*M)
        // SC: O(N*M+N*M)
    }
};