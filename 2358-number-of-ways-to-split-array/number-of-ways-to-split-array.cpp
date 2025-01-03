class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        long sum=0,sum1=0;
        for(int i=0;i<n;i++){
sum+=nums[i];
        }
        for(int i=0;i<n-1;i++){
            sum1+=nums[i];
            sum-=nums[i];
            if(sum1>=sum)
            ans++;
        }
        return ans;
    }
};