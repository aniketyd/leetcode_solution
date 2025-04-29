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
    if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

    auto heuristic = [&](int x, int y) {
        return max(abs(n - 1 - x), abs(n - 1 - y)); // Chebyshev distance
    };

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, 0, 1, 1 + heuristic(0, 0)});

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int x = current.x, y = current.y;

        if (visited[x][y]) continue;  // if already visited, skip
        visited[x][y] = true;          // mark as visited only when popping

        if (x == n-1 && y == n-1) return current.g;

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                grid[nx][ny] == 0) {
                int new_g = current.g + 1;
                int h = heuristic(nx, ny);
                pq.push({nx, ny, new_g, new_g + h});
            }
        }
    }

    return -1; // No path found
}
};