class Solution {
public:
    vector<vector<int>>dp;
    int fun(vector<int>&nums,int i,int j){
      
        if(j-i==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mi=0;
        for(int k=i+1;k<j;k++){
            mi=max(mi,fun(nums,i,k)+fun(nums,k,j)+nums[i]*nums[k]*nums[j]);
        }
        return dp[i][j]=mi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        nums.push_back(1);
         reverse(nums.begin(),nums.end());
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return fun(nums,0,n-1);
    }
};