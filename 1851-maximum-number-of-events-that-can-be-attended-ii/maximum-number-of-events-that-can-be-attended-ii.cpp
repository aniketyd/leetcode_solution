#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        // 1. Sort events by end day (ascending)
        sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        
        // 2. Extract the end days into a separate array for binary search
        vector<int> ends(n);
        for (int i = 0; i < n; ++i) {
            ends[i] = events[i][1];
        }
        
        // 3. DP table: dp[i][j] = max value by choosing at most j events
        //    from among the first i events (1-based in DP).
        //    We allocate (n+1) x (k+1), initialize all to 0.
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0LL));
        
        // 4. Fill the DP table
        //    i loops from 1..n (refers to events[i-1])
        for (int i = 1; i <= n; ++i) {
            int start_i = events[i - 1][0];
            int value_i = events[i - 1][2];
            
            // Find the last event index p (0-based) whose end < start_i
            // Among events[0..i-2], we look for the first end >= start_i,
            // then go one step back.
            int lo = 0, hi = i - 1; 
            // binary_search for the first index in [0..i-2] with ends[idx] >= start_i
            int p = -1;
            {
                auto it = lower_bound(ends.begin(), ends.begin() + (i - 1), start_i);
                if (it == ends.begin()) {
                    // no event ends before start_i
                    p = -1;
                } else {
                    // step one back
                    p = int(it - ends.begin()) - 1;
                }
            }
            
            // Now fill dp[i][j] for j = 1..k
            for (int j = 1; j <= k; ++j) {
                // Option 1: skip event i
                long long skip = dp[i - 1][j];
                
                // Option 2: take event i → add value_i to dp[p+1][j-1], if p >= 0
                long long take = value_i;
                if (p >= 0) {
                    take += dp[p + 1][j - 1];
                }
                
                dp[i][j] = max(skip, take);
            }
       
        }
        
        
        return dp[n][k];
    }
};
