class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        unordered_set<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)st.insert(nums[i]);
        int cnt=0,c=st.size(),ans=0;
        for(int i=0;i<n;i++){
              while(cnt!=c&&j<n){
                if(mp[nums[j]]==0)
                cnt++;
                mp[nums[j]]++;j++;
              }
              if(cnt==c){
               ans+=n-j+1;
              }
              if(mp[nums[i]]==1)
              cnt--;
              mp[nums[i]]--;
        }
        return ans;
    }
};