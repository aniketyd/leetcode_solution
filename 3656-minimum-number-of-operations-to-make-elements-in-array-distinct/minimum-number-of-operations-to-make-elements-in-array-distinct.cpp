class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int j=0;
        for(int i=n-1;i>=0;i--){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                j=i+1;
                break;
            }
        }
        return (j+2)/3;
    }
};