class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<tuple<int, int, int>> cells;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cells.emplace_back(mat[i][j], i, j);

    sort(cells.begin(), cells.end());

    vector<int> rowMax(m, 0), colMax(n, 0);
    int res = 0;

    // Temporary storage for this layer
    unordered_map<int, vector<pair<int, int>>> sameValGroups;

    for (int i = 0; i < cells.size();) {
        int j = i;
        // group same-value cells
        while (j < cells.size() && get<0>(cells[i]) == get<0>(cells[j]))
            ++j;

        vector<tuple<int, int, int>> updates;
        for (int k = i; k < j; ++k) {
            auto [val, r, c] = cells[k];
            int best = max(rowMax[r], colMax[c]) + 1;
            updates.emplace_back(r, c, best);
            res = max(res, best);
        }

        for (auto [r, c, best] : updates) {
            rowMax[r] = max(rowMax[r], best);
            colMax[c] = max(colMax[c], best);
        }

        i = j;
    }

    return res;
}

};