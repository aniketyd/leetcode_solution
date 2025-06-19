class Solution {
public:
// 1 2 4  6 14
    bool check(vector<long long>&prefixSum,long long k,int mid){
        int left=(mid+1)/2;
        int right=mid/2;
        int n=prefixSum.size();
        long long ans=1e15;
        for(int i=(mid+1)/2;i<n;i++){
            if(i+right==n)break;
            int num=prefixSum[i]-prefixSum[i-1];
            long long temp=1LL*left*num-(prefixSum[i]-prefixSum[i-left]);
            temp+=prefixSum[i+right]-prefixSum[i]-(1LL*right*num);
             ans=min(ans,temp);
        }
        
        if(ans<=k)return true;
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefixSum(n+1);
        for(int i=1;i<=n;i++){
           prefixSum[i]+=prefixSum[i-1]+nums[i-1];
        }
        int low=2,high=n,ans=1;
        while(low<=high){
            int mid=low+(high-low)/2;
             if(check(prefixSum,k,mid)){
                ans=mid;
                low=mid+1;
             }
             else{
                high=mid-1;
             }
        }
        return ans;
    }
};