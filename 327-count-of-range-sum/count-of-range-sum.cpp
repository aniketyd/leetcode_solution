class Solution {
public:
    int lwr, uppr;

    int merge(vector<long long>& prefixSum, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1, k = mid + 1;

        for (int i = low; i <= mid; ++i) {
            long long lowerBound = prefixSum[i] + lwr;
            long long upperBound = prefixSum[i] + uppr;

            while (k <= high && prefixSum[k] < lowerBound) ++k;
            while (j <= high && prefixSum[j] <= upperBound) ++j;

            count += (j - k);
        }

        // Merge step
        vector<long long> temp(high - low + 1);
        int i = low, r = mid + 1, t = 0;

        while (i <= mid && r <= high) {
            temp[t++] = (prefixSum[i] <= prefixSum[r]) ? prefixSum[i++] : prefixSum[r++];
        }
        while (i <= mid) temp[t++] = prefixSum[i++];
        while (r <= high) temp[t++] = prefixSum[r++];
        for (int i = 0; i < temp.size(); ++i) {
            prefixSum[low + i] = temp[i];
        }

        return count;
    }

    int mergeSort(vector<long long>& prefixSum, int low, int high) {
        if (low == high) {
            return (prefixSum[low] >= lwr && prefixSum[low] <= uppr) ? 1 : 0;
        }
        int mid = low + (high - low) / 2;
        int left = mergeSort(prefixSum, low, mid);
        int right = mergeSort(prefixSum, mid + 1, high);
        int count = merge(prefixSum, low, mid, high);
        return left + right + count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lwr = lower;
        this->uppr = upper;
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return mergeSort(prefixSum, 1, n);
    }
};
