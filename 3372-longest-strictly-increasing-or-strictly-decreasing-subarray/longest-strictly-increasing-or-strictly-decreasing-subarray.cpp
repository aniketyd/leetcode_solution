class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int in=1,de=1;
        int ans=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                in++;
                de=1;
            }
            else if(nums[i]<nums[i-1]){
                de++;
                in=1;
            }
            else{
                in=1;
                de=1;
            }
            ans=max(ans,max(in,de));
        }
        return ans;
    }
};