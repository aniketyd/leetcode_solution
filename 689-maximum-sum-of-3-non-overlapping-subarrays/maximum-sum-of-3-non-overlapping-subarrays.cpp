class Solution {
public:
//dp[i][j]=maximum sum of j subarray from 0 to i 
//dp[i][j]=max(dp[i-1][j],pf[i]-pf[i-k]+dp[i-k][j-1]); 
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(4,0));
        
        vector<int>pf(n+1);
        for(int i=0;i<n;i++)
        pf[i+1]+=pf[i]+nums[i];
        for(int j=1;j<=3;j++){
            for(int i=j*k;i<=n;i++){
              dp[i][j]=max(dp[i-1][j],pf[i]-pf[i-k]+dp[i-k][j-1]);
              

            }
        }
        vector<int>ans;
        int i;
        for( i=n-1;i>=1;i--){
             if(dp[i][3]!=dp[i+1][3])
            { ans.push_back(i-k+1);i-=k;break;}
        }
        for(;i>=1;i--){
            if(dp[i][2]!=dp[i+1][2])
            {
                ans.push_back(i-k+1);i-=k;break;
            }
        }
         for(;i>=0;i--){
            if(dp[i][1]!=dp[i+1][1])
            {
                ans.push_back(i-k+1);i--;break;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};