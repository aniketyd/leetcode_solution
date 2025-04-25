class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int cnt=0;
        mp[0]=1;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k)
            cnt++;
            cnt%=modulo;
            
            int req=(cnt-k+modulo)%modulo;
             ans+=mp[req];
             mp[cnt]++;
        } 
        return ans;
    }
};