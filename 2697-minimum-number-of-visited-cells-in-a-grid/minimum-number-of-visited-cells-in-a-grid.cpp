#define pii pair<int, int>
#define F first
#define S second
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<set<int>> rem_rows(cols);
        vector<set<int>> rem_cols(rows);
        
        for (int r = 0; r < rows; r ++) {
            for (int c = 0; c < cols; c ++) {
                rem_rows[c].insert(r);
                rem_cols[r].insert(c);
            }
        }
        
        vector<vector<int>> dist (rows, vector<int>(cols, -1));
        dist[0][0] = 1;
        
        queue<pii> q;
        q.push({0, 0});
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            int r = cur.F, c = cur.S;
                        
            vector<int> erase_cols;
            for (
                auto it = rem_cols[r].lower_bound(c+1); 
                it != rem_cols[r].end() && *it <= (c + grid[r][c]); 
                it ++
            ) {
                dist[r][*it] = dist[r][c] + 1;
                q.push({r, *it});
                erase_cols.push_back(*it);
            }
            for (auto c : erase_cols) {
                rem_cols[r].erase(c);
                rem_rows[c].erase(r);
            }
            
            vector<int> erase_rows;
            for (
                auto it = rem_rows[c].lower_bound(r+1);
                it != rem_rows[c].end() && *it <= (r + grid[r][c]);
                it ++
            ) {
                dist[*it][c] = dist[r][c] + 1;
                q.push({*it, c});
                erase_rows.push_back(*it);
            }
            for (auto r : erase_rows) {
                rem_cols[r].erase(c);
                rem_rows[c].erase(r);
            }
        }
                
        return dist[rows-1][cols-1];
    }
};