class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numIndex(n);
        for (int i = 0; i < n; i++) {
            numIndex[i] = {nums[i], i};
        }

        sort(numIndex.begin(), numIndex.end());

        long long score = 0;
        vector<bool> marked(n, false);
        for (int i = 0; i < n; i++) {
            if (!marked[numIndex[i].second]) {
                score += numIndex[i].first;
                marked[max(numIndex[i].second - 1, 0)] = true;
                marked[numIndex[i].second] = true;
                marked[min(numIndex[i].second + 1, n - 1)] = true;
            }
        }

        return score;
    }
};