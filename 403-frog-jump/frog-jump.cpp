class Solution {
public:

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<unordered_set<long long>>dp(n+1);
        dp[0].insert(0);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int diff=stones[i]-stones[j];
                for(long long k=diff-1;k<1LL*diff+2;k++){
                    if(dp[j].count(k)&&k>=0)
                    dp[i].insert(diff);
                }
            }
        }
        if(dp[n-1].size()>0)return true;
        return false;
    }
};