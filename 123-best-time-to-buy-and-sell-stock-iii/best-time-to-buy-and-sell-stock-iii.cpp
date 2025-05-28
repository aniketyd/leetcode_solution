class Solution {
public:
    int N;
    int memo(int i, int j, int k, vector<int> &p, vector<vector<vector<int>>> &dp) {

        if(i == 2 || j == N || k == 2)
            return 0;

        if(dp[i][j][k] > -1)
            return dp[i][j][k];

        // skip current one 
        int choice1 = memo(i, j + 1, k, p, dp);
        
        int choice2;
        // if have bought and sell now
        if(k == 1)
            choice2 = p[j] + memo(i + 1, j + 1, k - 1, p, dp);
        // buy now
        else 
            choice2 = -p[j] + memo(i, j + 1, k + 1, p, dp);

        return dp[i][j][k] = max(choice1, choice2);
    }

    int maxProfit(vector<int>& prices) {
        N = prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(N, vector<int>(2, -1))); 
        
        return memo(0, 0, 0, prices, dp);
    }

};