class Solution {
public:
vector<vector<int>>pre;
#define mod 1000000007
    int countWays(vector<int>nums){
         int n=nums.size();
         if(n==1||n==0)return 1;
         vector<int>left,right;
         
         for(int i=1;i<n;i++){
             if(nums[i]>nums[0])right.push_back(nums[i]);
             if(nums[i]<nums[0])left.push_back(nums[i]);
         }
         int leftresult=countWays(left);
         int rightresult=countWays(right);
         int possibleComb=pre[n-1][min((int)left.size(),(int)right.size())];
         int numComb=(1LL*leftresult*rightresult)%mod;
         numComb=(1LL*numComb*possibleComb)%mod;
         return numComb;
         
    }
    int numOfWays(vector<int>& nums) {
       int n = nums.size();
pre.resize(n + 1, vector<int>(n + 1));

// Initialize base cases
for (int i = 0; i <= n; i++) {
    pre[i][0] = 1;
    pre[i][i] = 1;
}


for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
        pre[i][j] = (pre[i - 1][j - 1] + pre[i - 1][j]) % mod;
    }
}
        
        return (countWays(nums)-1+mod)%mod;

    }
};