class Solution {
public:
  int dp[3003];
  int fun(int n, int k){
    if(n==0)return 0;
    if(n<0)return 1e9;
    if(dp[n]!=-1)return dp[n];
    int ans=1e9;
    for(int i=k;i<=n;i+=10)
     ans=min(ans,1+fun(n-i,k));
     return dp[n]=ans;
  }
    int minimumNumbers(int num, int k) {
        if(num==0)
        return 0;
        if(k==0){
            if(num%10==0)
            return 1;
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        int ans=fun(num,k);
        if(ans>=1e8)return -1;
        return ans;
    }
};