class Solution {
public:
   vector<vector<int>>dp;
   
    int minCost(int n, vector<int>& cuts) {
      cuts.push_back(n);
      cuts.push_back(0);
      sort(cuts.begin(),cuts.end());
      dp.resize(cuts.size(),vector<int>(cuts.size(),1e9));
      for(int i=0;i<cuts.size();i++){
        dp[i][i]=0;
        if(i+1<cuts.size())
        dp[i][i+1]=0;
      }
      for(int i=cuts.size()-1;i>=0;i--){
        for(int j=i+1;j<cuts.size();j++){
            for(int k=i+1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);
            }
        }
      }
       return dp[0][cuts.size()-1];
    }
};