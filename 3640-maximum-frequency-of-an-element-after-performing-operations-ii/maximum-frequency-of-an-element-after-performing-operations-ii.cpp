class Solution {
public:
        int maxFrequency(vector<int>& A, int k, int numOperations) {
        sort(A.begin(), A.end());

        // Case 1
        unordered_map<int, int> count;
        int res = 0, i = 0, j = 0, n = A.size();
        for (int a : A) {
            while (j < n && A[j] <= (a + 1LL*k)) {
                count[A[j]]++;
                j++;
            }
            while (i < n && A[i] < a - k) {
                count[A[i]]--;
                i++;
            }
            int cur = min(j - i, count[a] + numOperations);
            res = max(res, cur);
        }

        // Case 2
        
        for (int i = 0, j = 0; j < n; j++) {
            while (1LL*(A[i] + 1LL*k + k) < A[j]) {
                i++;
            }
            res = max(res, min(j - i + 1, numOperations));
        }
        return res;
    }
};