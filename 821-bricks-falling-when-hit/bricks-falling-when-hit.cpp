class DSU {
public:
    vector<int> parent, rank, sz;

    DSU(int N) {
        parent.resize(N);
        rank.resize(N);
        sz.resize(N, 1);
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;

        if (rank[xr] < rank[yr])
            swap(xr, yr);

        if (rank[xr] == rank[yr])
            rank[xr]++;

        parent[yr] = xr;
        sz[xr] += sz[yr];
    }

    int size(int x) {
        return sz[find(x)];
    }

    int top() {
        return size(parent.size() - 1) - 1;
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int R = grid.size(), C = grid[0].size();
        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        vector<vector<int>> A = grid;
        for (auto& hit : hits)
            A[hit[0]][hit[1]] = 0;

        DSU dsu(R * C + 1);
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (A[r][c] == 1) {
                    int i = r * C + c;
                    if (r == 0)
                        dsu.unite(i, R * C);
                    if (r > 0 && A[r - 1][c] == 1)
                        dsu.unite(i, (r - 1) * C + c);
                    if (c > 0 && A[r][c - 1] == 1)
                        dsu.unite(i, r * C + c - 1);
                }
            }
        }

        int t = hits.size();
        vector<int> ans(t);
        --t;

        while (t >= 0) {
            int r = hits[t][0];
            int c = hits[t][1];
            int preRoof = dsu.top();

            if (grid[r][c] == 0) {
                ans[t--] = 0;
            } else {
                int i = r * C + c;
                A[r][c] = 1;

                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C && A[nr][nc] == 1)
                        dsu.unite(i, nr * C + nc);
                }

                if (r == 0)
                    dsu.unite(i, R * C);

                int newRoof = dsu.top();
                ans[t--] = max(0, newRoof - preRoof - 1);
            }
        }

        return ans;
    }
};
