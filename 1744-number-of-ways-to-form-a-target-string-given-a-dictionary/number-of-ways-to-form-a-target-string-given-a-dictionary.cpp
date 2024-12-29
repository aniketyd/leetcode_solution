class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int m=words[0].size();
        int s=target.size();
        int mod=1e9+7;
        unordered_map<int,unordered_map<int,int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            mp[j+1][words[i][j]]++;
        }
        vector<vector<int>>dp(s+1,vector<int>(m+1));
        for(int i=0;i<=m;i++)
        dp[0][i]=1;
        for(int i=1;i<=s;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i][j-1];
                if(mp[j][target[i-1]]>=1){
                    dp[i][j]=(dp[i][j]+1LL*mp[j][target[i-1]]*dp[i-1][j-1]%mod)%mod;
                }
            }
        }
        return dp[s][m];
    }
};