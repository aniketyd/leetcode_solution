class Solution {
public:
  static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
   }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        n=rides.size();
        vector<long long>dp(n),temp;
        sort(rides.begin(),rides.end(),cmp);

        for(int i=0;i<n;i++){
          temp.push_back(rides[i][1]);
        }
        dp[0]=rides[0][1]-rides[0][0]+rides[0][2];
        for(int i=1;i<n;i++){
            int start=rides[i][0];
            auto indx=upper_bound(temp.begin(),temp.end(),start)-temp.begin();
            if(indx==0)
            dp[i]=max(dp[i-1],1LL*rides[i][1]-start+rides[i][2]);
            else
            dp[i]=max(dp[i-1],dp[indx-1]+rides[i][1]-start+rides[i][2]);
        }
        return dp[n-1];
    }
};