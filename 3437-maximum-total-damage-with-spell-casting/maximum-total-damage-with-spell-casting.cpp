class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size();
        vector<int>v;
        sort(power.begin(),power.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[power[i]]++;
        }
        for(int i=0;i<n-1;i++){
            if(power[i]!=power[i+1])
            v.push_back(power[i]);
        }
        v.push_back(power[n-1]);
        vector<long long>dp(v.size()+1);
        dp[0]=1LL*mp[v[0]]*v[0];
        for(int i=1;i<v.size();i++){
            long long ans=0;
            for(int j=i-1;j>=i-3&&j>=0;j--){
                 if(v[i]-v[j]>2){
                      ans=dp[j];
                      break;
                 }
            }
            dp[i]=max(ans+1LL*mp[v[i]]*v[i],dp[i-1]);
        }
        return dp[v.size()-1];
        
    }
};