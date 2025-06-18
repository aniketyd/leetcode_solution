class Solution {
private:
    // For generating all possible subset sums. Can also be done via recursion.
    // If we take an element, add it to sum; otherwise, move forward.
    // Base case: if idx == n, push sum to ans.
    vector<int> helper(vector<int>& nums, int start, int end, int offset) {
        int n = end - start + 1;
        vector<int> ans;

        // Looping from 0 to 2^n - this is equivalent to 2^n as there are a total of 2^n subsets.
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;

            // Looping through indices 0, 1, 2, ..., n
            for (int j = 0; j < n; j++) {
                // If it is a set bit, then 1 && 1 gives 1 (which means take it),
                // and 0 means do not take it.
                // We iterate over n bits using left shift.
                if (i & (1 << j)) {
                    sum += nums[j + offset];
                }
            }

            ans.push_back(sum);
        }

        return ans;
    }

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        // Taking an offset because in the right half, the result will be in the range 0 to n/2.
        // However, we need to add the offset to ensure it moves to its respective right half.
        // In the left half, the offset remains 0.
        // 'left' contains all possible subset sums from the left half,
        // and 'right' contains all possible subset sums from the right half.
        vector<int> left = helper(nums, 0, n / 2 - 1, 0);
        vector<int> right = helper(nums, n / 2, n - 1, n / 2);

        sort(right.begin(), right.end());
        int ans = 1e9;
        for (int idx = 0; idx < left.size(); idx++) {
            // We want the subset sum to be as close to 'goal' as possible.
            // If 'x' is the left subset sum and 'y' is the right subset sum,
            // we want x + y ≈ goal, so we need y ≤ goal - x.
            int x = left[idx];
            int y = goal - x;

            // Find the first value in 'right' that is ≥ y.
            int lb = lower_bound(right.begin(), right.end(), y) - right.begin();

            // If 'lb' is within range, check the minimum absolute difference.
            // Also, check the previous value to ensure we get the minimum difference.
            if (lb < right.size()) {
                ans = min(ans, abs(goal - x - right[lb]));
            }

            // If 'lb' goes out of range, check the previous value.
            if (lb > 0) {
                ans = min(ans, abs(goal - x - right[lb - 1]));
            }
        }

        return ans;
    }
};