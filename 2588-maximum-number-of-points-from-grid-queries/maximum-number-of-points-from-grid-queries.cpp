class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int r = grid.size(), c = grid[0].size(), n = queries.size();
        vector<int> ans(n, 0);
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        // Directions for 4-way movement
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // Min-heap to process queries in increasing order
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({queries[i], i});
        }

        // Min-heap for grid traversal (to get the smallest unvisited value)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> gridHeap;
        gridHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int count = 0;
        int lastQueryValue = -1;

        while (!pq.empty()) {
            int queryVal = pq.top().first;
            int queryIndex = pq.top().second;
            pq.pop();

            // Process BFS for new reachable cells
            while (!gridHeap.empty() && gridHeap.top().first < queryVal) {
                int val = gridHeap.top().first;
                int row = gridHeap.top().second.first;
                int col = gridHeap.top().second.second;
                gridHeap.pop();
                count++;

                for (const auto& d : dir) {
                    int newRow = row + d[0];
                    int newCol = col + d[1];

                    if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c && !visited[newRow][newCol]) {
                        gridHeap.push({grid[newRow][newCol], {newRow, newCol}});
                        visited[newRow][newCol] = true;
                    }
                }
            }
            ans[queryIndex] = count;
        }
        return ans;
    }
};