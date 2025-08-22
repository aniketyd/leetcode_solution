class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        vector<int>v;
        for(int i=0;i<n;i++){
               mp[nums[i]]++;
        }
        for(auto val:mp){
            v.push_back(val.first);
        }
        vector<int>dp(v.size()+1);
       dp[0]=0;
        for(int i=0;i<v.size();i++){
            int prev=0;
            if(i!=0){
                if(v[i-1]==v[i]-1)
                prev=dp[i-1];
                else
                prev=dp[i];
            
            }
            
              dp[i+1]=max(prev+mp[v[i]]*v[i],dp[i]);
        }
       
        return dp[v.size()];

    }
};