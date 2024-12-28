class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1));
        vector<vector<int>>t;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              vector<int>temp(3);
              temp[0]=v[i][j];
               temp[1]=i;
                temp[2]=j;
              t.push_back(temp);
            }
        }
        sort(t.begin(),t.end());
        int ans=1;
        int adjx[4]={0,1,-1,0};
        int adjy[4]={1,0,0,-1};
        for(int i=0;i<t.size();i++){
          int x=t[i][1];
          int y=t[i][2];
          for(int j=0;j<4;j++)
          {
            int xx=adjx[j]+x;
            int yy=adjy[j]+y;
            if(xx>=0&&yy>=0&&xx<n&&yy<m&&v[xx][yy]<v[x][y]){
                dp[x][y]=max(dp[x][y],dp[xx][yy]+1);
            }
          }
          ans=max(ans,dp[x][y]);
        }
        return ans;

    }
};