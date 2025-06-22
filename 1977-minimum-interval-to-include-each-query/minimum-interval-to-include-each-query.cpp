class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < n; ++i) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());
        sort(intervals.begin(), intervals.end());

        vector<int> result(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        int i = 0;

        for (auto& [query, idx] : sortedQueries) {
            // Add all intervals whose left <= query
            while (i < intervals.size() && intervals[i][0] <= query) {
                int l = intervals[i][0], r = intervals[i][1];
                minHeap.push({r - l + 1, r});
                ++i;
            }

            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                result[idx] = minHeap.top().first;
            }
        }

        return result;
    }
};