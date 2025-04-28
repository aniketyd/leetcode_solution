class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long ans=1LL*(n)*(n+1)/2;
        long long sum=0LL,cnt=0LL;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n&&((1LL*(sum)*(j-i))<k)){
                sum+=nums[j];
                  j++;
            }
            if((1LL*sum*(j-i))>=k)
            cnt+=n-j+1;
            sum-=nums[i];
        }
      
        return ans-cnt;
    }
};