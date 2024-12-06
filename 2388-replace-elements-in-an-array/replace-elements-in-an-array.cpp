class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        int m=operations.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<m;i++){
            mp[operations[i][1]]=mp[operations[i][0]];
            mp[operations[i][0]]=-1;
        }
        for(auto val:mp){
            if(val.second!=-1)
            nums[val.second]=val.first;
        }
        return nums;
    }
};