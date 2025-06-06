class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
 int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        int sum=0;
        for(int i=0;i<m;i++)
        if(matrix[0][i]=='1'){dp[0][i]=1;sum=1;}
        for(int i=1;i<n;i++)
        if(matrix[i][0]=='1'){dp[i][0]=1;sum=1;}
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
              if(matrix[i][j]!='0')
             {
              if(i-1>=0)
              dp[i][j]=dp[i-1][j]+1;
              if(j-1>=0)
              dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
              if(i-1>=0&&j-1>=0)
              dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
              }
              sum=max(sum,dp[i][j]);
             
            }
        }
return sum*sum;

    }
};