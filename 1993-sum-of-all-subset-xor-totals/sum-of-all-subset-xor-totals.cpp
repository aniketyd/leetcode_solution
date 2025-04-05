class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1025, -1)); // memo table
        return XORSum(nums, 0, 0, dp);
    }

private:
    int XORSum(vector<int>& nums, int index, int currentXOR, vector<vector<int>>& dp) {
        if (index == nums.size()) return currentXOR;

        if (dp[index][currentXOR] != -1) return dp[index][currentXOR];

        int withElement = XORSum(nums, index + 1, currentXOR ^ nums[index], dp);
        int withoutElement = XORSum(nums, index + 1, currentXOR, dp);

        return dp[index][currentXOR] = withElement + withoutElement;
    }
};
