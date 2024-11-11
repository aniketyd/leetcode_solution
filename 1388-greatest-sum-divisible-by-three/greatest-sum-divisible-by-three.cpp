class Solution {
public:
int dp[40005][4];
   int fun(vector<int>&v,int i,int m){
       if(i<0){
        if(m==0)
        return 0;
        return -1e9;
       }
       if(dp[i][m]!=-1)return dp[i][m];
       int res;
       res=fun(v,i-1,m);
       res=max(res,fun(v,i-1,(m+v[i]%3)%3)+v[i]);
       return dp[i][m]=res;
   }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]%3==0)sum+=nums[i];
          else v.push_back(nums[i]);
            
        }
        memset(dp,-1,sizeof(dp));
        sum+=fun(v,v.size()-1,0);
return sum;
    }
};