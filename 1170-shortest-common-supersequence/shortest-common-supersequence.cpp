class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n = text1.size();
int m = text2.size();
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        if (text1[i - 1] == text2[j - 1]) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
}
int i=n,j=m;
string lcs="";
      while(i>0&&j>0){
            if(i>0&&dp[i][j]==dp[i-1][j])
           { i--;continue;}
            if(j>0&&dp[i][j]==dp[i][j-1])
           { j--;continue;}
           lcs+=text1[i-1];
           i--;j--;
      }
      if(lcs.size()==0)return text1+text2;
      reverse(lcs.begin(),lcs.end());
      
      string ans="";
      int j1=0,j2=0;
      for(int i=0;i<lcs.size();i++){
        string str1="",str2="";
          while(j1<n&&text1[j1]!=lcs[i]){
            str1+=text1[j1];
            j1++;
          }
          while(j2<m&&text2[j2]!=lcs[i]){
            str2+=text2[j2];
            j2++;
          }
          ans+=str1;
          ans+=str2;
          ans+=lcs[i];
          j1++;j2++;}
           while(j1<n){
            ans+=text1[j1];
            j1++;
          }
          while(j2<m){
            ans+=text2[j2];
            j2++;
          }
          return ans;
    }
};