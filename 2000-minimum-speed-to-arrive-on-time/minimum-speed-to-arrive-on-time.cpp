class Solution {
public:
    int minSpeedOnTime(vector<int>& nums, double m) {
         int n=nums.size();
        
        auto help=[&](int mid){
            double sum=0;
           for(int i=0;i<n-1;i++){
             sum+=((nums[i]+mid-1)/mid);
           }
           sum+=nums[n-1]*1.0/mid;
           return sum<=m;
        };
        int ans=-1;
        int low=1,high=1e7;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(help(mid)){
                ans=mid;
               high=mid-1;
            }
            else
             low=mid+1;
        }
        return ans;
    }
};