class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
           priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n=grid.size();
        int m=grid[0].size();
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        int adx[4]={0,1,0,-1};
        int ady[4]={-1,0,1,0};
        dis[0][0]=grid[0][0];
        while(!pq.empty()){
            int mi=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(dis[i][j]<mi) continue;
            for(int k=0;k<4;k++){
                int ax=i+adx[k];
                int ay=j+ady[k];
                if(ax>=0&&ay>=0&&ax<n&&ay<m&&dis[ax][ay]>(max(mi,grid[ax][ay]))){
                    dis[ax][ay]=max(mi,grid[ax][ay]);
                    pq.push({dis[ax][ay],{ax,ay}});
                }
            }
            
        }
        return dis[n-1][m-1];
    }
};