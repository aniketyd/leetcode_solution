class Solution {
public:
    int helper(vector<int>&nums, int mid){
        int i=0,j=0,cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(j<n&&nums[j]-nums[i]<=mid){
                j++;
            }
            cnt+=j-i-1;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=0,high=1e7,ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            int res=helper(nums,mid);
            int res2=helper(nums,mid-1);
            if(res>=k&&res2<k)
            return mid;
            if(res>=k){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};