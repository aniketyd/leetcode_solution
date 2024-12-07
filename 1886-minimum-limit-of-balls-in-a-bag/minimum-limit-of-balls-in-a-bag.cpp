class Solution {
public:
    int minimumSize(vector<int>& nums, int m) {
        int n=nums.size();
        
        auto help=[&](int mid){
            long sum=0;
           for(int i=0;i<n;i++){
             sum+=((nums[i]+mid-1)/mid)-1;
           }
           return sum<=m;
        };
        int ans;
        int low=1,high=1e9;
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