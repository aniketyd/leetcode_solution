class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int s=primes.size();
        vector<long long>v(n);
        v[0]=1;
        vector<long long>crr(s);
        for(int i=1;i<n;i++){
           for(int j=0;j<s;j++){
            if(j==0)v[i]=1LL*v[crr[j]]*primes[j];
            v[i]=min(v[i],1LL*v[crr[j]]*primes[j]);
           }
           for(int j=0;j<s;j++){
            if(v[i]==1LL*v[crr[j]]*primes[j])crr[j]++;
           }
        }
       
        return v[n-1];
    }
};