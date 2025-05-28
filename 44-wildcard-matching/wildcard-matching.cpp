class Solution {
public:
vector<vector<int>>dp;
 
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        dp.resize(n1+1,vector<int>(n2+1,0));
        dp[0][0]=1;
        for(int i=0;i<n2;i++){
            if(p[i]=='*')
            dp[0][i+1]=1;
            else
            break;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                bool res=false;
                   if(p[j-1]=='?'||s[i-1]==p[j-1])
                           res|=dp[i-1][j-1];
                   if(p[j-1]=='*'){
                            res|=dp[i-1][j];
                             res|=dp[i][j-1];
                    }
                    dp[i][j]=res;
            }
        }
        return dp[n1][n2];
    }
};