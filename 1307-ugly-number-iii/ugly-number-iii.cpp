class Solution {
public:
#define ll long long
   long long fun(ll n,ll a,ll b,ll c){
      long long k=n/a;
      k+=n/b;
      k+=n/c;
      ll l1=(1LL*a*b)/__gcd(a,b);
      ll l2=(1LL*a*c)/__gcd(a,c);
      ll l3=(1LL*b*c)/__gcd(b,c);
      k-=n/l1;
      k-=n/l2;
      k-=n/l3;
      l1=(1LL*l1*c)/(__gcd(l1,c));
      k+=n/l1;
      return k;
   }
    int nthUglyNumber(int n, int a, int b, int c) {
        int low=0, high=2*1e9,ans;
        while(low<=high){
              int mid=low+(high-low)/2;
              long long res=fun(mid,a,b,c);
              if(res>=n){
                high=mid-1;
                ans=mid;
              }
              else
              {
                low=mid+1;
              }
        }
       
        return ans;
    }
};