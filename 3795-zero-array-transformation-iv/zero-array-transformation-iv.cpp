class Solution {
public:
   int fun(vector<int>&nums,vector<vector<int>>&q,int mid){
      int n=nums.size();
      vector<vector<int>>v(n+1);
      for(int i=0;i<mid;i++){
          for(int j=q[i][0];j<=q[i][1];j++){
            v[j].push_back(q[i][2]);
          }
      }
      for(int i=0;i<n;i++){
          vector<int>dp(nums[i]+1);
          dp[0]=1;
          for(int j=0;j<v[i].size();j++){
            vector<int>temp=dp;
            for(int k=0;k<=nums[i];k++){
                  if(k-v[i][j]>=0){
                    temp[k]=temp[k]|dp[k-v[i][j]];
                  }
            }
            dp=temp;
          }
          if(dp[nums[i]]==0)return false;
      }
      return true;
   }
   int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       int n=nums.size();
       int low=0,high=queries.size();
       int ans=-1;
       while(low<=high){
        int mid=(low+high)/2;
        if(!fun(nums,queries,mid)){
            
            low=mid+1;
        }
        else{ans=mid;
        high=mid-1;}
       }
       return ans;
    }
};