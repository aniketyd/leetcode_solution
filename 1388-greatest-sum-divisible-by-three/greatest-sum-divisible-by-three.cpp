#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

class Solution {
public:
    int maxSumDivThree(std::vector<int>& nums) {
        // Initialize a dp array of size 3 for storing max sums with remainders 0, 1, and 2
        std::vector<int> dp(3, -1e9);
        dp[0] = 0;  // Base case: sum 0 with remainder 0 is achievable with no elements

        for (int num : nums) {
            // Copy the current state to update based on it (to avoid overwriting during iteration)
            std::vector<int> dpNew = dp;

            for (int m = 0; m < 3; m++) {
                if (dp[m] != -1e9) {  // If there's a valid sum with remainder m
                    int newRemainder = (m + num % 3) % 3;
                    dpNew[newRemainder] = std::max(dpNew[newRemainder], dp[m] + num);
                }
            }

            dp = dpNew;  // Update dp to reflect changes made in dpNew
        }

        // Result is the maximum sum with remainder 0 (sum divisible by 3)
        return dp[0];
    }
};
