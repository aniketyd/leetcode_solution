class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(K+1,vector<int>(2,0)));
        
        for(int i=n-1;i>=0;i--){
            for(int j=K-1;j>=0;j--){
                for(int k=0;k<2;k++){
                    dp[i][j][k]=dp[i+1][j][k];
                    if(k==1)
                      dp[i][j][k]=max(dp[i][j][k],prices[i]+dp[i+1][j+1][0]);
                      else
                      dp[i][j][k]=max(dp[i][j][k],-1*prices[i]+dp[i+1][j][1]);
                }
            }
        }
        return dp[0][0][0];
    }
};