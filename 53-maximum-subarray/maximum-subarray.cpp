class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int n=nums.size();
        
        int sum=0;
        int mx=INT_MIN,mi=0;int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
           
            mi=min(mi,sum);
           
            ans=max(ans,(sum-mi));
            mx=max(mx,nums[i]);
        }
        if(mx<0)return mx;
        return ans;
    }
};