class Solution {
public:
#define ll long long
    ll dp[16][2][2][2];
    ll fun(vector<int>&arr,int idx,int carry,int a,int b){
        if(idx<0){
            if(carry==0)return 1;
            return 0;
        }
        if(dp[idx][carry][a][b]!=-1)return dp[idx][carry][a][b];
        ll sum=0;
        
            for(int i=0;i<=9;i++){
                int diff,newCarry=0;
                if(a==1&&i>0)break;
              diff=arr[idx]-i;
            if(carry)
            diff--;
              if(diff<0){
                diff+=10;
                newCarry=1;
              }
              int newa=a;
              if(i==0)newa=1;
             if(diff==0&&b==1){
                sum+=fun(arr,idx-1,newCarry,newa,b);
              }
              else if(b==0){
                if(diff==0){
                    sum+=fun(arr,idx-1,newCarry,newa,1);
                }
                else
                sum+=fun(arr,idx-1,newCarry,newa,b);
              }
            }
        
         return dp[idx][carry][a][b]=sum;
    }
    long long countNoZeroPairs(long long n) {
        vector<int>arr;
        bool flag=false;
        while(n>0){
            arr.push_back(n%10);
            if(n%10==0)flag=true;
            n/=10;
        }
        int s=arr.size();
        reverse(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        int t=0;
        if(!flag)
        t=2;
        return fun(arr,s-1,0,0,0)-t;

    }
};