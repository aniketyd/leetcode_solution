class Solution {
public:
//dp[i]=mx product of integer i similar to given condition
//dp[i]=dp[i-k]*dp[k]
    int integerBreak(int n) {
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
           for(int j=1;j<i;j++){
               dp[i]=max(dp[i],dp[i-j]*dp[j]);
               dp[i]=max(dp[i],(i-j)*j);
               dp[i]=max(dp[i],(i-j)*dp[j]);
               dp[i]=max(dp[i],dp[i-j]*j);
           }
        }
        return dp[n];
    }
};