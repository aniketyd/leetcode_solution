class Solution {
public:
    #define ll long long
    const int MOD = 1e9+7;

    ll power(ll x, ll y, ll p) { 
        ll res = 1;
        x = x % p;
        if (x == 0) return 0; 

        while (y > 0) { 
            if (y & 1) 
                res = (res * x) % p; 
            y = y >> 1;
            x = (x * x) % p; 
        } 
        return res; 
    } 

    int countBalancedPermutations(string num) {
        vector<int> fr(10);
        int sum = 0;
        for (auto c : num) {
            fr[c - '0']++;
            sum += (c - '0');
        }
        
        if (sum % 2 != 0) return 0;
        int n = num.size();
        vector<int> fact(n + 1, 1), ifact(n + 1, 1);
        
        for (int i = 1; i <= n; i++) {
            fact[i] = (1LL * i * fact[i - 1]) % MOD;
            ifact[i] = power(fact[i], MOD - 2, MOD);  // Use modular inverse correctly
        }

        int permutationsCount = (1LL * fact[n / 2] * fact[(n + 1) / 2]) % MOD;
        vector<vector<vector<int>>> dp(10, vector<vector<int>>(sum / 2 + 1, vector<int>(n / 2 + 1, -1)));

        std::function<int(int, int, int)> f = [&](int number, int taken, int currentSum) -> int {
            if (number == 10) {
                return (currentSum == sum / 2 && taken == n / 2 ? permutationsCount : 0);
            }
            if (currentSum > sum / 2 || taken > n / 2) return 0;
            if (dp[number][currentSum][taken] != -1) return dp[number][currentSum][taken];

            long long ways = 0;
            for (int i = 0; i <= std::min(fr[number], n / 2 - taken); i++) {
                ways = (ways + (1LL * ifact[i] * ifact[fr[number] - i] % MOD * f(number + 1, taken + i, currentSum + i * number)) % MOD) % MOD;
            }
            
            return dp[number][currentSum][taken] = ways;
        };

        return f(0, 0, 0);
    }
};
