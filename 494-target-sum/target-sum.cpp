class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum+abs(target))%2==1) return 0;
         target=(sum+abs(target))/2;
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            vector<int>crr=dp;
            for(int j=0;j<=target;j++){
                if(j-nums[i]>=0){
                    crr[j]=crr[j]+dp[j-nums[i]];
                }

            }
            dp=crr;
        }
        return dp[target];
    }
};