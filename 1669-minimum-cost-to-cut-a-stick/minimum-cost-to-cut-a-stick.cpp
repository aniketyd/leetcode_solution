class Solution {
public:
   vector<vector<int>>dp;
    int fun(vector<int>&cuts,int i,int j){
        if(i==j||j-i==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
         int mx=1e9;
        for(int k=i+1;k<j;k++){
            mx=min(mx,fun(cuts,i,k)+fun(cuts,k,j)+cuts[j]-cuts[i]);
        }
        return dp[i][j]=mx;
    }
    int minCost(int n, vector<int>& cuts) {
      cuts.push_back(n);
      cuts.push_back(0);
      sort(cuts.begin(),cuts.end());
      dp.resize(cuts.size(),vector<int>(cuts.size(),-1));
       return fun(cuts,0,cuts.size()-1);
    }
};