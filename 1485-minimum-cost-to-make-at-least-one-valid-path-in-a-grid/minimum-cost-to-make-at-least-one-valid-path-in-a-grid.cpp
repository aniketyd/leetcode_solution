class Solution {
public:
    int direction(int nX,int nY,int x,int y){
        if(nY-y==1)return 1;
        if(nY-y==-1)return 2;
        if(nX-x==1)return 3;
        return 4;
    }
    int minCost(vector<vector<int>>& grid) {
        int n= grid.size(), m = grid[0].size();
        deque<pair<int,pair<int,int>>>dq;
        dq.push_front({0,{0,0}});
        int adx[4]={0,1,0,-1};
        int ady[4]={1,0,-1,0};
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        while(!dq.empty()){
            auto val=dq.front();
            int wt=val.first;
            int x=val.second.first;
            int y=val.second.second;
            dq.pop_front();
            if(x==n-1&&y==m-1)return wt;
            if(dis[x][y]<wt)continue;
            for(int k=0;k<4;k++){
                int nX=x+adx[k];
                int nY=y+ady[k];
                int cost=(direction(nX,nY,x,y)==grid[x][y])?0:1;
                if(nX>=0&&nX<n&&nY>=0&&nY<m&&dis[nX][nY]>(wt+cost)){
                    dis[nX][nY]=wt+cost;
                    if(cost==0)
                    dq.push_front({wt,{nX,nY}});
                    else
                    dq.push_back({wt+1,{nX,nY}});
                }
            }
        }
        return 0;
    }
};