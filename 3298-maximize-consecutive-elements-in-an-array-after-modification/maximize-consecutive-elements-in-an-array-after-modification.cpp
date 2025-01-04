class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>dp;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
          int ans1=1+dp[nums[i]-1];
          int ans2=1+dp[nums[i]];
          int ans3=max(ans1,ans2);
          ans=max(ans,ans3);
          dp[nums[i]+1]=max(ans2,dp[nums[i]+1]);
          dp[nums[i]]=max(ans1,dp[nums[i]]);

        }
        


        return ans;
    }
};
// 1 1 1 2 5
// dp[1]=1, dp[2]=1
//dp[1]=1, dp[2]=2
//dp[2]=2 dp[3]=3
