class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0],mi=nums[n-1];
        int start=-1,end=-1;
        for(int i=1;i<n;i++){
           if(mx>nums[i])end=i;
           mx=max(mx,nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            if(mi<nums[i])start=i;
            mi=min(mi,nums[i]);
        }
        if(start==-1)return 0;
        return end-start+1;
    }
};