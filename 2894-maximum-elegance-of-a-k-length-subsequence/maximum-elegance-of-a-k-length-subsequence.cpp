class Solution {
public:
using ll = long long;
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
           sort(items.begin(), items.end(), [](auto &a, auto &b) {
            return a[0] > b[0];  // Sort by profit descending
        });

        unordered_set<int> used_categories;
        priority_queue<int, vector<int>, greater<int>> duplicate_heap; // min-heap
        ll profit = 0;
        ll maxElegance = 0;

        // Step 1: Take first k items
        for (int i = 0; i < k; ++i) {
            profit += items[i][0];
            int cat = items[i][1];
            if (used_categories.count(cat)) {
                duplicate_heap.push(items[i][0]); // potential replaceable
            } else {
                used_categories.insert(cat);
            }
        }

        // Step 2: Compute elegance
        int distinct = used_categories.size();
        maxElegance = profit + 1LL * distinct * distinct;

        // Step 3: Try replacing duplicates with new categories
        for (int i = k; i < items.size(); ++i) {
            int cat = items[i][1];
            int val = items[i][0];

            if (used_categories.count(cat)) continue; // already have this category

            if (duplicate_heap.empty()) break; // no more to replace

            int to_remove = duplicate_heap.top(); duplicate_heap.pop();
            profit += val - to_remove;
            used_categories.insert(cat);
            distinct++;

            maxElegance = max(maxElegance, profit + 1LL * distinct * distinct);
        }

        return maxElegance;
    }
};