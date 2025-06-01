class Solution {
public:
 
    long long distributeCandies(int n, int limit) {
        vector<int>dp(n+1);
        for(int i=0;i<=n;i++){
            if(i<=limit){
                dp[i]=i+1;
            }
            else{
                int initialPoint=i-limit;
                dp[i]=(limit-initialPoint+1);
                dp[i]=max(0,dp[i]);
            }
        }
long long ans=0;
        for(int i=0;i<=limit;i++){
           if(n-i>=0){
            ans+=dp[n-i];
           }
           else break;
        }
        return ans;
    }
};