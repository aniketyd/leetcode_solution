class Solution {
public:
vector<vector<int>>dp;
   int minSum(string &s1,string &s2,int i,int j){
        if(i<0){
            int sum=0;
            while(j>=0){
               sum+=s2[j];j--;
            }
            return sum;
        }
        if(j<0){
            int sum=0;
            while(i>=0){sum+=s1[i];i--;}return sum;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int res=1e8;
        if(s1[i]==s2[j]){
           res= minSum(s1,s2,i-1,j-1);
        }
        res=min(res,minSum(s1,s2,i-1,j)+s1[i]);
        res=min(res,minSum(s1,s2,i,j-1)+s2[j]);
        return dp[i][j]=res;

   }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return minSum(s1,s2,n-1,m-1);
    }
};