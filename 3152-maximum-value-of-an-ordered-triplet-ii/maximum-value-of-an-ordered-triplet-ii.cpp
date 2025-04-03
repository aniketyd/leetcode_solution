class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        int mx=max(nums[0],nums[1]);
        long long ans=0;
        int diff=nums[0]-nums[1];
        for(int i=2;i<n;i++){
             ans=max(ans,1LL*(diff)*nums[i]);
             diff=max(diff,mx-nums[i]);
             mx=max(mx,nums[i]);
        }
        return max(ans,0LL);
    }
};