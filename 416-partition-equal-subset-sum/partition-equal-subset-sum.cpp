class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        sum=sum/2;
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
          vector<int>crr=dp;
            for(int j=0;j<=(sum);j++){
                if(j-nums[i]>=0)
                crr[j]=crr[j]|dp[j-nums[i]];
            }
            for(int j=0;j<=sum;j++) {dp[j]=crr[j];}
    
        }

        return dp[sum];
    }
};