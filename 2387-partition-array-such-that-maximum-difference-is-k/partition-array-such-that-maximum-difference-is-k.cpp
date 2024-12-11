class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       int i=0,c=0;
       while(i<n){
          auto it=lower_bound(nums.begin(),nums.end(),nums[i]+k+1)-nums.begin();
          c++;
          i=it;
       }
       return c;
    }
};