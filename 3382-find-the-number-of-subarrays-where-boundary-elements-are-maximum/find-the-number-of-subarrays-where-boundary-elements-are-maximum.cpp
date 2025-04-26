class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        unordered_map<int,vector<int>>mp;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<=nums[i])
            st.pop();
            if(st.empty()){
                 mp[nums[i]].push_back(i);
                ans+=mp[nums[i]].size();
                st.push(i);
               
            }
            else{
                int tp=st.top();
                 mp[nums[i]].push_back(i);
                auto it=upper_bound(mp[nums[i]].begin(),mp[nums[i]].end(),tp)-mp[nums[i]].begin();
                ans+=mp[nums[i]].size()-it;
                st.push(i);
               
            }
        }
        return ans;
    }
};