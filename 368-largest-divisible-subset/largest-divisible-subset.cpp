class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,1),h(n,-1);
        for(int i=0;i<n;i++){
            int mx=0;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(mx<dp[j]){
                        mx=dp[j];
                        h[i]=j;
                    }
                }
            }
            dp[i]=mx+1;
        }
        int m=0,idx;
       for(int i=0;i<n;i++){
           if(m<dp[i]){
               m=dp[i];
               idx=i;
           }
       }
      
       vector<int>v;
       while(idx!=-1){
           v.push_back(nums[idx]);
           idx=h[idx];
       }
       reverse(v.begin(),v.end());
       return v;
    }
};