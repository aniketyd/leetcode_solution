class Solution {
public:
    int dp[51][33000]; // dp[i][bits]: min stickers using s[i:] to cover bits of target
    int n, m;

    int solve(int i, int bits, int val, vector<string>& s, string& t) {
        if ((bits & val) == val) return 0; // all bits in val covered
        if (i >= n) return 1e5; // used all stickers
        if (dp[i][bits] != -1) return dp[i][bits];

        int ntake = solve(i + 1, bits, val, s, t); // skip current sticker
        int take = 1e5;
        int bit = bits;

        for (int j = 0; j < s[i].size(); j++) {
            for (int k = 0; k < m; k++) {
                if ((bit & (1 << k)) != 0) continue; // already taken
                if (s[i][j] == t[k]) {
                    bit |= (1 << k); // mark as covered
                    break; // take only once per matching char
                }
            }
        }

        if (bit != bits) {
            take = min(take, 1 + solve(i, bit, val, s, t)); // reuse current sticker
        }

        return dp[i][bits] = min(take, ntake);
    }

    int minStickers(vector<string>& s, string t) {
        n = s.size();
        m = t.size();
        memset(dp, -1, sizeof(dp));
        int val = (1 << m) - 1;
        int res = solve(0, 0, val, s, t);
        return res >= 1e5 ? -1 : res;
    }
};