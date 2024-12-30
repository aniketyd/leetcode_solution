class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,0);
        dp[zero]++;
        dp[one]++;
        int mod=1e9+7;
        for(int i=1;i<=high;i++){
            if(i-zero>=0)
            dp[i]=(dp[i]+dp[i-zero])%mod;
            if(i-one>=0)
            dp[i]=(dp[i]+dp[i-one])%mod;
        }
        int sum=0;
        for(int i=low;i<=high;i++){
            sum=(sum+dp[i])%mod;
        }
        return sum;
    }
};