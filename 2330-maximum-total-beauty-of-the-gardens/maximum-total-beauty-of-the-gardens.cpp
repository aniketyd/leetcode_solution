class Solution {
public:

    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(),flowers.end(),greater<int>());
        int n=flowers.size();
        long long remFlower=newFlowers,maxBeauty=0;
        vector<long long>suffix(n);
        suffix[n-1]=flowers[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]+=suffix[i+1]+flowers[i];
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(remFlower<0)break;
          
            if(flowers[i]<target){
                int low=flowers[n-1],high=target-1,ans;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    auto indx=upper_bound(flowers.begin()+i,flowers.end(),mid,greater<int>())-flowers.begin();
                   
                    long long res=0;
                    if(indx!=n)
                     res=1LL*(n-indx)*mid-suffix[indx];
                    if(res<=remFlower){
                        ans=mid;
                        low=mid+1;
                    }
                    else
                    high=mid-1;
                }
             
                maxBeauty=max(maxBeauty,1LL*ans*partial+1LL*i*full);
                remFlower-=target-flowers[i];
            }
            if(remFlower>=0)
           maxBeauty=max(maxBeauty,1LL*(i+1)*full);
           
        }
        return maxBeauty;
    }
};