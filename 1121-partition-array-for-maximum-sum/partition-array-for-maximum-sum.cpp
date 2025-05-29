class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
      vector<int>dp(n+1);
        
       for(int i=n-1;i>=0;i--){
        int mx=arr[i];
        for(int j=i;j<n&&j<(i+k);j++){
           mx=max(mx,arr[j]);
           dp[i]=max(dp[i],dp[j+1]+(j-i+1)*mx);
        }
       }
       return dp[0];
    }
};