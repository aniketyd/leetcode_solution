class Solution {
public:
#define ll long long
int mod=1e9+7;
    ll  power(ll x, ll y, ll p) 
{ 
    ll res = 1;     // Initialize result 
 
    x = x % p; // Update x if it is more than or 
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
    int countBalancedPermutations(string num) {
        vector<int>mp(10);int sum=0;
        for(int i=0;i<num.size();i++){
            mp[num[i]-'0']++;
            sum+=num[i]-'0';
        }
        if(sum&1)return 0;
        int n=num.size();
        vector<int>fact(n+1,1),ifact(n+1,1);

        for(int i=1;i<=n;i++)
       { fact[i]=(1LL*i*fact[i-1])%mod;
        ifact[i]=power(fact[i],mod-2,mod);}

       long long k=(1LL*fact[n/2]*fact[(n+1)/2])%mod;
        vector<vector<vector<int>>>dp(10,vector<vector<int>>(sum/2+1,vector<int>(n/2+1,-1)));
        auto f=[&](int d,int s,int l,auto &&self)-> int{
              if(d==10){
                if(s==sum/2&&l==n/2){
                    return k;
                }
                return 0;
              }
              if(s>sum/2||l>n/2)return 0;
            if(dp[d][s][l]!=-1)return dp[d][s][l];
            long long way=0;
            for(int i=0;i<=min(mp[d],n/2-l);i++){
              way=(way+(1LL*(1LL*ifact[i]*ifact[mp[d]-i])%mod*self(d+1,s+i*d,l+i,self))%mod)%mod;
            }
            return dp[d][s][l]=way;
        };
        return f(0,0,0,f);
    }
};