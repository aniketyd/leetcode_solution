class Solution {
public:
int dp[102][102];
   bool f(string &s1,string &s2,string &s3,int i, int j,int k){
         if(i==-1){
           while(j>=0&&s2[j]==s3[k]){
            j--;
            k--;
           }
           if(j==-1)return true;
           return false;
         }
         if(j==-1){
            while(i>=0&&s1[i]==s3[k]){
                i--;
                k--;
            }
            if(i==-1)return true;
            return false;
         }
         if(dp[i][j]!=-1)return dp[i][j];
         bool ans=false;
         if(i>=0&&s1[i]==s3[k])
         ans=ans|f(s1,s2,s3,i-1,j,k-1);
         if(j>=0&&s2[j]==s3[k])
         ans=ans|f(s1,s2,s3,i,j-1,k-1);
         return dp[i][j]=ans;

   }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        int n1=s1.size();
        int n2=s2.size();
        int n=s3.size();
        if(n1+n2!=n)return false;
        return f(s1,s2,s3,n1-1,n2-1,n-1);
    }
};