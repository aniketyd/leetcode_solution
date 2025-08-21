

class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>vis(n,vector<int>(m)),mi(n,vector<int>(m,1e8));
        for(int i=0;i<n;i++){
            mi[i][0]=h[i][0];
            pq.push(make_tuple(h[i][0],i,0));
            if(mi[i][m-1]==1e8){
                mi[i][m-1]=h[i][m-1];
                 pq.push(make_tuple(h[i][m-1],i,m-1));
            }
        }
        for(int i=1;i<m-1;i++){
            mi[0][i]=h[0][i];
            pq.push(make_tuple(h[0][i],0,i));
            if(mi[n-1][i]==1e8){
                mi[n-1][i]=h[n-1][i];
                 pq.push(make_tuple(h[n-1][i],n-1,i));
            }
        }
        int adx[4]={0,1,-1,0};
        int ady[4]={1,0,0,-1};
        while(!pq.empty()){
            auto tp=pq.top();pq.pop();
          int ht = get<0>(tp), x = get<1>(tp), y = get<2>(tp);
            for(int i=0;i<4;i++){
                int xx=x+adx[i];
                int yy=y+ady[i];
                if(xx>=0&&xx<n&&yy>=0&&yy<m&&mi[xx][yy]>max(ht,h[xx][yy])){
                   mi[xx][yy]=max(ht,h[xx][yy]);
                   pq.push(make_tuple(mi[xx][yy],xx,yy));
                  
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