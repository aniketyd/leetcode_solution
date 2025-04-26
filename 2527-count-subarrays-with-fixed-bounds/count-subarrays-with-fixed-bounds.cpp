class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        vector<int>pre(n),pre2(n),pre3(n);
        int mi=n,mx=n,p=-1,p2=-1;

        for(int i=n-1;i>=0;i--){
            if(nums[i]==maxK)p=i;
            if(nums[i]==minK)p2=i;
            if(nums[i]<minK)mi=i;
            if(nums[i]>maxK)mx=i;
            pre2[i]=p;
            pre3[i]=p2;
            pre[i]=min(mi,mx);
        }
     
        int c=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=minK&&nums[i]<=maxK){
                c++;
            }
            else if(nums[i]<minK || nums[i]>maxK)
            c=0;
            if(nums[i]==maxK&&pre3[i]!=-1&&pre[i]>pre3[i]){
                 int d=pre[pre3[i]]-pre3[i];
                
                 ans+=1LL*c*d;
                 c=0;
            }
            if(nums[i]==minK&&pre2[i]!=-1&&pre[i]>pre2[i]){
                
                int d=pre[pre2[i]]-pre2[i];
              
                ans+=1LL*c*d;
                
                c=0;
            }
        }
        return ans;
    }
};