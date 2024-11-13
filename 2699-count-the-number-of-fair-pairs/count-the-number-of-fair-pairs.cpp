class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long sum=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int l=lower_bound(nums.begin(),nums.begin()+i,lower-nums[i])-nums.begin();
            int u=upper_bound(nums.begin(),nums.begin()+i,upper-nums[i])-nums.begin();
            sum+=(u-l);
        }
        return sum;
    }
};