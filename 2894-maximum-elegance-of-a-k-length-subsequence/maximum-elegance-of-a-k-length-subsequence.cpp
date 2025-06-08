class Solution {
public:
using ll = long long;
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
          unordered_map<int, vector<ll>> catProfits;
        for (auto &it : items) {
            ll profit = it[0];
            int cat   = it[1];
            catProfits[cat].push_back(profit);
        }
        
        // 2) For each category, pick the top profit as "best",
        //    and all the rest go into "extras"
        vector<ll> bestProfits;
        vector<ll> extras;
        bestProfits.reserve(catProfits.size());
        
        for (auto &p : catProfits) {
            auto &vec = p.second;
            sort(vec.begin(), vec.end(), greater<ll>());
            bestProfits.push_back(vec[0]);
            for (int i = 1; i < vec.size(); ++i)
                extras.push_back(vec[i]);
        }
        
        // 3) Sort both lists descending
        sort(bestProfits.begin(), bestProfits.end(), greater<ll>());
        sort(extras.begin(),      extras.end(),      greater<ll>());
        
        int m = bestProfits.size();
        int e = extras.size();
        
        // 4) Build prefix sums
        vector<ll> prefBest(m+1, 0), prefExtra(e+1, 0);
        for (int i = 0; i < m; ++i) prefBest[i+1] = prefBest[i] + bestProfits[i];
        for (int i = 0; i < e; ++i) prefExtra[i+1] = prefExtra[i] + extras[i];
        
        // 5) Try taking t distinct categories (with their top profits)
        //    and (k - t) extras, for all valid t, track max elegance
        ll ans = 0;
        for (int t = 1; t <= m && t <= k; ++t) {
            int needExtra = k - t;
            if (needExtra > e) continue; // not enough extras
            ll profitSum = prefBest[t] + prefExtra[needExtra];
            ll elegance  = profitSum + 1LL * t * t;
            ans = max(ans, elegance);
        }
        
        return ans;
    
    }
};