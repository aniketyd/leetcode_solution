class Solution {
public:
   const int mx=1e6+10;
    vector<int>seive;
    vector<int>prime;
     void algo() {
        seive.resize(mx, 0);
        seive[0] = seive[1] = 1; // Mark 0 and 1 as non-prime
        for (int i = 2; i < mx; i++) {
            if (seive[i] == 0) { // i is prime
                for (long long j = 1LL*i * i; j < mx; j += i) { // Start marking from i*i
                    seive[j] = 1;
                }
                prime.push_back(i); // Store primes
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        seive.resize(mx+10,0);
        algo();
        auto it=lower_bound(prime.begin(),prime.end(),left)-prime.begin();
        int ans=-1,ans2=-1;
        int mi=1e9;
        for(it++;it<prime.size()&&prime[it]<=right;it++){
            if(prime[it]-prime[it-1]<mi){
                mi=prime[it]-prime[it-1];
                ans=prime[it];
                ans2=prime[it-1];
            }
        }
        return {ans2,ans};
    }
};