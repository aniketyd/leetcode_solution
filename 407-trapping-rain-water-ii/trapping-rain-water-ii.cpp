

class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>vis(n,vector<int>(m)),mi(n,vector<int>(m));
        for(int i=0;i<n;i++){
            vis[i][0]=1;
            pq.push(make_tuple(h[i][0],i,0));
            if(!vis[i][m-1]){
                vis[i][m-1]=1;
                 pq.push(make_tuple(h[i][m-1],i,m-1));
            }
        }
        for(int i=1;i<m-1;i++){
            vis[0][i]=1;
            pq.push(make_tuple(h[0][i],0,i));
            if(!vis[n-1][i]){
                vis[n-1][i]=1;
                 pq.push(make_tuple(h[n-1][i],n-1,i));
            }
        }
        int adx[4]={0,1,-1,0};
        int ady[4]={1,0,0,-1};
        while(!pq.empty()){
            auto tp=pq.top();pq.pop();
          int ht = get<0>(tp), x = get<1>(tp), y = get<2>(tp);
            for(int i=0;i<4;i++){
                int xx=x+adx[i];int yy=y+ady[i];
                if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]){
                    vis[xx][yy]=1;
                    mi[xx][yy]=max(ht,h[xx][yy]);
                    if(ht<h[xx][yy]){
                        pq.push(make_tuple(h[xx][yy],xx,yy));
                    }
                    else{
                        pq.push(make_tuple(ht,xx,yy));
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                ans+=mi[i][j]-h[i][j];
            }
        }
        return ans;
    }
};