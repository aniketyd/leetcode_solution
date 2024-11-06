class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<long long int,vector<long long int>> mp;
        for(int i=0;i<nums.size();i++){
            long long int diff=nums[i]%space;
            mp[diff].push_back(nums[i]);
        }
        long long int mx=-1e18;
        for(auto it:mp){
           
            if((long long int)it.second.size()>mx){
                mx=(long long int)it.second.size();
            }
           
        }
       
        long long int res;
        for(auto it:mp){
            vector<long long int> v=it.second;
            sort(v.begin(),v.end());
            if(v.size()==mx){
               
                res=min(res,v[0]);
            }
        }
        return res;
    }
};