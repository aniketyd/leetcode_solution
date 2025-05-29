class Solution {
public:
//dp[i][j]= minimum cuts needed for a palindrome partition from i to j of s.

    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,3000);
        dp[n]=0;
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            dp[i]=min(dp[i],dp[i+1]+1);
            int l=i-1,r=i+1;
            
            while(l>=0&&r<n&&s[l]==s[r]){
                
                dp[l]=min(dp[l],dp[r+1]+1);
                
                l--;r++;
                
            }
             l=i,r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                dp[l]=min(dp[l],dp[r+1]+1);l--;r++;
            }
        }
        return dp[0]-1;
    }
};