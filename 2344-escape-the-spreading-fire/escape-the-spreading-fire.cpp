class Solution {
public:
    vector<vector<long>> a;
    int n, m;
    
    bool good(long mn) {
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        vis[0][0] = 1;
        
        queue<array<long, 3>> q;
        q.push({0, 0, mn});
        
        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            long dis = q.front()[2];
            
            q.pop();
            
            if(x == n - 1 and y == m - 1) {
                return 1;
            }
            if(a[x][y] <= dis) {
                continue;
            }
            
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            
            for(int t = 0; t < 4; ++t) {
                int i = x + dx[t];
                int j = y + dy[t];
                
                if(min(i, j) >= 0 and i < n and j < m and !vis[i][j] and a[x][y] != -1 and dis + 1 <= a[i][j]) {
                    q.push({i, j, dis + 1});
                    vis[i][j] = 1;
                }
            }
        }
        
        return 0;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        a.resize(n, vector<long> (m, 1e10));
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    a[i][j] = 0;
                    q.push({i, j});
                } else if(grid[i][j] == 2) {
                    a[i][j] = -1;
                }
            }
        }
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            
            for(int t = 0; t < 4; ++t) {
                int i = x + dx[t];
                int j = y + dy[t];
                
                if(min(i, j) >= 0 and i < n and j < m and a[i][j] != -1 and a[x][y] + 1 < a[i][j]) {
                    a[i][j] = a[x][y] + 1;
                    q.push({i, j});
                }
            }
        }
        
        long l = 0, r = 1e9, best = -1;
        
        while(l <= r) {
            long mid = l + (r - l) / 2;
            if(good(mid)) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return best;
    }
};