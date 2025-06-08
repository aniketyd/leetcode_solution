class Solution {
public:
    int minOperations(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    // Remove duplicates
    vector<int> uniqueNums;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || nums[i] != nums[i - 1])
            uniqueNums.push_back(nums[i]);
    }

    int res = n;
    for (int i = 0; i < uniqueNums.size(); ++i) {
        int maxVal = uniqueNums[i] + n - 1;
        // Binary search to find how many elements can be in the range [uniqueNums[i], maxVal]
        int j = upper_bound(uniqueNums.begin(), uniqueNums.end(), maxVal) - uniqueNums.begin();
        int validCount = j - i;
        res = min(res, n - validCount);
    }
    return res;
}
};