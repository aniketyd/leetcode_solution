class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int it=lower_bound(nums.begin(),nums.end(),nums[i]+2*k+1)-nums.begin();
            ans=max(ans,it-i);
           
        }
        return ans;
    }
};