class Solution {
public:
    int solve(int i, int j, int val, vector<int>& nums, vector<int>& andValues, vector<vector<unordered_map<int, int>>>& dp) {
        if (i >= nums.size()) {
            if (j >= andValues.size()) return 0;
            else return 1000001;
        }
        if (j >= andValues.size()) return 1000001;

        if (dp[i][j].count(val)) return dp[i][j][val];

        if (val == -1) val = nums[i];
        else val = val & nums[i];

        int ans = INT_MAX;
        if (val == andValues[j]) {
            ans = nums[i] + min(ans, solve(i + 1, j + 1, -1, nums, andValues, dp));
            ans = min(ans, solve(i + 1, j, val, nums, andValues, dp));
        } else {
            ans = min(ans, solve(i + 1, j, val, nums, andValues, dp));
        }

        return dp[i][j][val] = ans;
    }

    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        int m = andValues.size();
        if (m > n) return -1;
        
        
        vector<vector<unordered_map<int, int>>> dp(n + 1, vector<unordered_map<int, int>>(m + 1));

        int ans = solve(0, 0, -1, nums, andValues, dp);
        return ans > 1000000 ? -1 : ans;
    }
};