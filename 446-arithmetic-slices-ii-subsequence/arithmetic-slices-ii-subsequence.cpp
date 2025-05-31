class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,unordered_map<long long,int>>dp;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                long long diff=1LL*nums[i]-nums[j];
                dp[i][diff]+=dp[j][diff]+1;
            }
            for(auto val:dp[i])
            ans+=val.second;
        }
        ans-=(n*(n-1))/2;
        return ans;
    }
};