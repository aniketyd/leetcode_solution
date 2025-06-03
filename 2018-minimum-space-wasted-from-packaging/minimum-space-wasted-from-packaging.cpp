class Solution {
public:
   static const long long MOD = 1000000007;

long long minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
    int n = packages.size();
    sort(packages.begin(), packages.end());

    // Build prefix sum array of package sizes
    vector<long long> prefix(n);
    prefix[0] = packages[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + packages[i];
    }

    long long bestWaste = LLONG_MAX;

    // For each supplier
    for (auto& supplierBoxes : boxes) {
        sort(supplierBoxes.begin(), supplierBoxes.end());

        // If the largest box can't fit the largest package, skip
        if (supplierBoxes.back() < packages.back()) {
            continue;
        }

        long long waste = 0;
        int prevIdx = 0;  // number of packages already placed

        // Try to place as many packages as possible using each box size
        for (int boxSize : supplierBoxes) {
            int idx = upper_bound(packages.begin(), packages.end(), boxSize) - packages.begin();
            int count = idx - prevIdx;
            if (count > 0) {
                long long rangeSum = prefix[idx - 1];
                if (prevIdx > 0) {
                    rangeSum -= prefix[prevIdx - 1];
                }
                waste += (long long)boxSize * count - rangeSum;
                prevIdx = idx;
            }
            if (prevIdx == n) {
                break;
            }
        }

        // If all packages were placed, consider this supplier
        if (prevIdx == n) {
            bestWaste = min(bestWaste, waste);
        }
    }

    if (bestWaste == LLONG_MAX) {
        return -1;
    }
    return bestWaste % MOD;
}
};