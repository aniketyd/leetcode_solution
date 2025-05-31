class Solution {
public:
vector<vector<int>>dp;
   bool fun(string &s,string &p,int i,int j){
          if(i==s.size()&&j==p.size())return true;
          if(i==s.size()||j==p.size())return false;
          if(dp[i][j]!=-1)return dp[i][j];
          bool res=false;
          if(j<(p.size()-1)&&p[j+1]=='*'){
                if(s[i]==p[j]||p[j]=='.'){
         //using jth character to math with s ith character
                    res|=fun(s,p,i+1,j);
                    res|=fun(s,p,i+1,j+2);
                }
               
                // skipping
                res|=fun(s,p,i,j+2);
          }
          else{
            // when ith of s is equal to jth of p
               if(s[i]==p[j]||p[j]=='.'){
                res|=fun(s,p,i+1,j+1);
               }
          }
          return dp[i][j]=res;
   }
    bool isMatch(string s, string p) {
        s.push_back('1');
        p.push_back('1');
        int n1=s.size();
        int n2=p.size();
     dp.resize(n1+1,vector<int>(n2+1,-1));
     return fun(s,p,0,0);
       
    }
};