class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++){
                if(j-coins[i]>=0&&dp[j-coins[i]]!=1e9)
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
        if(dp[amount]==1e9)return -1;
        return dp[amount];
    }
};