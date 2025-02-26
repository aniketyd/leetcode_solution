class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        
        int sum=0;
        int mx=0,mi=0;int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mx=max(mx,sum);
            mi=min(mi,sum);
            ans=max(ans,abs(mx-sum));
            ans=max(ans,abs(mi-sum));
            
        }
        return ans;
       
    }
};