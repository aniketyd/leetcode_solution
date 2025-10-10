class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
     int n=energy.size(),ans=-1e8;
     vector<int>dp(n,0);
     for(int i=n-1;i>=0;i--){
        int nxt=i+k;
        dp[i]=energy[i];
        if(nxt<n)
        dp[i]+=dp[nxt];
        ans=max(ans,dp[i]);
     }  
     return ans;
    }
};