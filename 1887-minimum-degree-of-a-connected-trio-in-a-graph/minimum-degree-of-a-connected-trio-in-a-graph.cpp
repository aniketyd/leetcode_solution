class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 0));
        vector<int> indegree(n+1, 0);
        for (auto &e:edges) {
            adjMatrix[min(e[0], e[1])][max(e[0], e[1])] = 1;
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (adjMatrix[i][j]) {
                    for (int k = j+1; k <= n; k++) {
                        if (adjMatrix[i][k] && adjMatrix[j][k]) {
                            ans = min(ans, indegree[i] + indegree[j] + indegree[k]-6);
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;

    }
};