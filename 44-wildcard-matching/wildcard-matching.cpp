class Solution {
public:
vector<vector<int>>dp;
    bool fun(string &s, string &p,int i,int j){
        if(i<0){
            while(j>=0&&p[j]=='*')j--;
            
            if(j<0){return true;}
            return false;
        }
        if(j<0)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        
        bool res=false;
        if(p[j]=='?'||s[i]==p[j])
        res|=fun(s,p,i-1,j-1);
        if(p[j]=='*'){
            res=res|fun(s,p,i-1,j);
            res|=fun(s,p,i,j-1);
        }
        return dp[i][j]=res;
    }
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return fun(s,p,n1-1,n2-1);
    }
};