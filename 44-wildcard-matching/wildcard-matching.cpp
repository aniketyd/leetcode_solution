class Solution {
public:

 
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<int>dp(n2+1,0);
        dp[0]=1;
        for(int i=0;i<n2;i++){
            if(p[i]=='*')
            dp[i+1]=1;
            else
            break;
        }
        for(int i=1;i<=n1;i++){
            vector<int>curDp(n2+1,0);
            for(int j=1;j<=n2;j++){
                bool res=false;
                   if(p[j-1]=='?'||s[i-1]==p[j-1])
                           res|=dp[j-1];
                   if(p[j-1]=='*'){
                            res|=dp[j];
                             res|=curDp[j-1];
                    }
                    curDp[j]=res;
            }
            dp=curDp;
        }
        return dp[n2];
    }
};