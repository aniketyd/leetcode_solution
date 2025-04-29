class Solution {
public:


struct Node {
    int x, y, g, f;
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

    auto heuristic = [&](int x, int y) {
        return max(abs(n - 1 - x), abs(n - 1 - y)); // Chebyshev
    };

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, 0, 1, 1 + heuristic(0, 0)});

    vector<vector<int>> g_score(n, vector<int>(n, INT_MAX));
    g_score[0][0] = 1;

    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        int x = curr.x, y = curr.y, g = curr.g;

        if (x == n - 1 && y == n - 1)
            return g;

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                int new_g = g + 1;
                if (new_g < g_score[nx][ny]) {
                    g_score[nx][ny] = new_g;
                    int f = new_g + heuristic(nx, ny);
                    pq.push({nx, ny, new_g, f});
                }
            }
        }
    }

    return -1;
}

};