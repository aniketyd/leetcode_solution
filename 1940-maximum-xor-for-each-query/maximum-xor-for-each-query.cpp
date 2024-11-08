class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int m) {
        int n=nums.size();
        vector<int>ans(n);
        int x=0;int msk=(1<<m)-1;
        for(int i=0;i<n;i++){
              x=x^nums[i];
              ans[n-1-i]=(~x)&(msk);
              
        }
   
        return ans;
    }
};