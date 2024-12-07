class Solution {
public:
    long long minimumTime(vector<int>& nums, int m) {
         int n=nums.size();
        
        auto help=[&](long long mid){
            long long sum=0;
           for(int i=0;i<n;i++){
             sum+=mid/nums[i];
             if(sum>=m)return true;
           }
           return sum>=m;
        };
        long long ans;
        long long low=1,high=1LL*m*(*max_element(nums.begin(),nums.end()));
        while(low<=high){
            long long mid=low+(high-low)/2;
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