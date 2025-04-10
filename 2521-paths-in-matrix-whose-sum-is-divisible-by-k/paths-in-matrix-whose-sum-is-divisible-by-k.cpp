class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // Notice that k is till 50
        // (a+b)%k = (a%k + b%k)%k;
        int m = grid.size(), n = grid[0].size(), mod=1000000000 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (k,0)));
        dp[m-1][n-1][grid[m-1][n-1]%k] = 1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i+1<m){
                    for(int l=0;l<k;l++){
                        dp[i][j][(grid[i][j]+l)%k]=(dp[i][j][(grid[i][j]+l)%k]+dp[i+1][j][l])%mod;
                    }
                }
                if(j+1<n){
                    for(int l=0;l<k;l++){
                        dp[i][j][(grid[i][j]+l)%k]=(dp[i][j][(grid[i][j]+l)%k]+dp[i][j+1][l])%mod;
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};