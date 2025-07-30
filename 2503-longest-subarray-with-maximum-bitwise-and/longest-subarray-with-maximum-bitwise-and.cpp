class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=-1;
        for(int i=0;i<n;i++){
          mx=max(mx,nums[i]);
        }
        int ans=0,c=0;
        for(int i=0;i<n;i++){
            if(mx==nums[i])c++;
            else
            c=0;
            ans=max(ans,c);
        }
        return ans;
    }
};