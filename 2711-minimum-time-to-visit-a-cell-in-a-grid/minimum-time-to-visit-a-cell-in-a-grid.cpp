class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][1]>1&&grid[1][0]>1)return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>time(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        time[0][0]=0;
        int adjx[4]={0,1,-1,0};
        int adjy[4]={1,0,0,-1};
        while(!pq.empty()){
            int curTime=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1&&y==m-1)return curTime;
            if(time[x][y]<curTime)continue;
            for(int k=0;k<4;k++){
                int nX=adjx[k]+x;
                int nY=adjy[k]+y;
                
                if(nX>=0&&nY>=0&&nX<n&&nY<m){
                    int extraTime=0;
                    if(grid[nX][nY]>(curTime+1)){
                        int diff=grid[nX][nY]-curTime-1;
                        extraTime=diff+diff%2;
                    }
                    if(time[nX][nY]>(curTime+extraTime+1)){
                        time[nX][nY]=curTime+extraTime+1;
                        pq.push({curTime+extraTime+1,{nX,nY}});
                    }
                }
            }

        }
        return -1;
    }
};