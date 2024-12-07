class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
         int n=nums.size();
        
        auto help=[&](int mid){
            long long sum=0;
           for(int i=0;i<n;i++){
             sum+=((nums[i])/mid);
           }
           return sum>=k;
        };
        int ans=0;
        int low=1,high=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(help(mid)){
                ans=mid;
               low=mid+1;
            }
            else
             high=mid-1;
        }
        return ans;
    }
};