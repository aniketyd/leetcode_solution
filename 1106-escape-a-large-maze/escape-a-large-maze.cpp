class Solution {
public:
    // Set to store all blocked cells
    set<vector<int>> block;

    // 4-directional moves
    vector<pair<int,int>> adj = {{-1,0}, {0,-1}, {0,1}, {1,0}};

    // BFS to check if escape is possible
    bool solve(int blocks_size, vector<int> &source, vector<int> &target) {
        int area = (blocks_size * blocks_size) / 2;  // Approx 20000

        set<pair<int,int>> visited;
        queue<pair<int,int>> que;
        que.push({source[0], source[1]});

        int cnt = 0; // how many unique cells visited

        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop();

            if (row == target[0] && col == target[1])
                return true; // reached target

            if (cnt > area)
                return true; // escaped blocked area

            for (auto [dx, dy] : adj) {
                int new_row = row + dx;
                int new_col = col + dy;

                // check bounds
                if (new_row >= 0 && new_row < 1e6 && new_col >= 0 && new_col < 1e6) {
                    pair<int,int> next = {new_row, new_col};

                    // check not visited or blocked
                    if (!visited.count(next) && !block.count({new_row, new_col})) {
                        que.push(next);
                        visited.insert(next);
                    }
                }
            }

            cnt++;
        }

        return false; // can't escape
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for (auto &x : blocked)
            block.insert(x);

        // check both source and target
        return solve(blocked.size(), source, target) && solve(blocked.size(), target, source);
    }
};
