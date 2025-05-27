class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int j=-1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                j=i;
                break;
            }
        }
        if(j==-1)return 0;
        int mi=1e6;
        int l,r;
        for(int i=j;i<n;i++){
              mi=min(mi,nums[i]);
        }
        for(int i=0;i<j;i++){
            if(nums[i]>mi){
                l=i;break;
            }
        }
        int m;
        for(int i=n-1;i>=1;i--){
            if(nums[i]<nums[i-1]){
                 m=i-1;break;
            }
        }
        int mx=-1e6;
        for(int i=0;i<=m;i++){
            mx=max(mx,nums[i]);
        }
        for(int i=n-1;i>m;i--){
            if(nums[i]<mx){
                r=i;break;
            }
        }
        
        return r-l+1;
    }
};