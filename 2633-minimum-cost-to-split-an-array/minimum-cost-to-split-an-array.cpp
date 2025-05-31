class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>dp(n+1,1e16);
        dp[0]=0;
        for(int i=1;i<=n;i++){
           unordered_map<int,int>mp;int c=0,cnt=0;
            for(int j=i;j<=n;j++){
                 mp[nums[j-1]]++;
                 if(mp[nums[j-1]]==2)c+=2;
                 else if(mp[nums[j-1]]!=1)
                 c++;
                 dp[j]=min(dp[j],dp[i-1]+c+k);
                
            }
        }
        return dp[n];
    }
};