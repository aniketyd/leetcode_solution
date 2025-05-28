class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int>dp(m+1,0);
        for(int i=1;i<=n;i++){
            vector<int>currDp(m+1);
            for(int j=1;j<=m;j++){
                currDp[j]=max(currDp[j-1],dp[j]);
                if(text1[i-1]==text2[j-1]){
                    currDp[j]=max(dp[j-1]+1,currDp[j]);
                }
               
            }
            dp=currDp;
        }
        return dp[m];
    }
};