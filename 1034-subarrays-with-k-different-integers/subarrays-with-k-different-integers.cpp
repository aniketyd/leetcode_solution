class Solution {
public:
    long long fun(vector<int>&v,int k){
        int n=v.size();
        unordered_map<int,int>mp;
        int a=0,j=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            while(a<k&&j<n){
                if(mp[v[j]]==0)
                a++;
                mp[v[j]]++;
                j++;
            }
            if(a>=k){
                ans+=n-j+1;
            }
            if(mp[v[i]]==1)a--;
            mp[v[i]]--;
            // cout<<i<<' '<<j<<' '<<ans<<endl;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        long long ans1=fun(nums,k);
        long long ans2=fun(nums,k+1);
        // cout<<ans1<<' '<<ans2<<endl;
        int ans=ans1-ans2;
        return ans;
    }
};