class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
         int n=values.size();
         vector<int>dp(n+1);
         for(int i=0;i<n;i++){
            if(i==0)dp[i]=values[i];
            else{
                dp[i]=max(values[i],dp[i-1]-1);
            }
         }
         int ans=0;
         for(int i=1;i<n;i++){
            ans=max(ans,dp[i-1]+values[i]-1);
         }
         return ans;
    }
};