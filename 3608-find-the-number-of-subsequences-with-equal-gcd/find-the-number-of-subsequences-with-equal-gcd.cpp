class Solution {
public:
int dp[210][210][210];
int N;int mod=1e9+7;
    int f(vector<int>&nums,int indx,int g1,int g2){
       if(indx>=N){
        if(g1==0||g2==0)return 0;
        if(g1==g2)return 1;
        else return 0;
       }
       if(dp[indx][g1][g2]==-1){
            int sum=0;
            if(g1==0){
                sum=f(nums,indx+1,nums[indx],g2);
            }
            else
            sum=f(nums,indx+1,__gcd(g1,nums[indx]),g2);
            if(g2==0)
            sum=(sum+f(nums,indx+1,g1,nums[indx]))%mod;
            else
            sum=(sum+f(nums,indx+1,g1,__gcd(g2,nums[indx])))%mod;

            sum=(sum+f(nums,indx+1,g1,g2))%mod;
            dp[indx][g1][g2]=sum;
       }
       return dp[indx][g1][g2];
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();N=n;
        int ans=0;
       
        return f(nums,0,0,0);
    }
};