class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int s, int k) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({s, k});
        vis[s][k] = 1; // Mark the starting cell as visited
        int sum = 0;
        int adx[] = {0, 1, 0, -1}; // Directions for adjacent cells
        int ady[] = {1, 0, -1, 0};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            sum += grid[x][y]; // Add fish count at the current cell

            // Explore all 4 adjacent cells
            for (int i = 0; i < 4; i++) {
                int nx = x + adx[i];
                int ny = y + ady[i];

                // Check boundaries and if the cell is unvisited and contains fish
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == 0 && grid[nx][ny] != 0) {
                    vis[nx][ny] = 1; // Mark as visited
                    q.push({nx, ny});
                }
            }
        }
        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0)); // Initialize the visited array

        // Traverse the entire grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is a water cell and not visited
                if (vis[i][j] == 0 && grid[i][j] != 0) {
                    // Perform BFS and find the total fish in this connected component
                    ans = max(ans, bfs(grid, vis, i, j));
                }
            }
        }

        return ans;
    }
};
