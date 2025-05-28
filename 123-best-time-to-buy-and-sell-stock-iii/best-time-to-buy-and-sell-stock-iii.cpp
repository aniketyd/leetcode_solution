class Solution {
public:
    int rec(int i, int transNo, vector<int>& prices, vector<vector<int>>& dp)    {
        /*base cond*/
        if(transNo == 4 || i == prices.size())  {
            //if we dont have a stock, then no transaction req -> return 0
            //if we have a stockBought, we need to sell it now, therefore profit = 0 here -> return 0
            return 0;
        }

        /*dp check*/
        if(dp[i][transNo] != -1) return dp[i][transNo];

        /*rec conds*/
        int profit;

        //has no stock right now
        if(transNo == 0 || transNo == 2)  {       //can even do if(transNo % 2 == 0)
            int buy = -prices[i] + rec(i+1, transNo+1, prices, dp);
            int not_buy = rec(i+1, transNo, prices, dp);

            profit = max(buy, not_buy);
        }

        //has stock right now
        else if(transNo == 1 || transNo == 3) {   //can even do if(transNo % 2 != 0)
            int sell = prices[i] + rec(i+1, transNo+1, prices, dp);
            int not_sell = rec(i+1, transNo, prices, dp);

            profit = max(sell, not_sell);
        }

        return dp[i][transNo] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int N=prices.size();
        vector<vector<int>> dp(N, vector<int>(4, -1));
        return rec(0,0, prices, dp);       //represents max profit
    }
};