class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]); // path compression
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;

        // Union by size: attach smaller tree under the larger one
        if (size[fx] < size[fy]) {
            parent[fx] = fy;
            size[fy] += size[fx];
        } else {
            parent[fy] = fx;
            size[fx] += size[fy];
        }
    }
};


class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        if (count(nums.begin(), nums.end(), 1)) return false;

        int MAX = *max_element(nums.begin(), nums.end());
        DSU dsu(2 * MAX + 1); // enough space for nums and primes

        // Sieve to get smallest prime factors
        vector<int> spf(MAX + 1);
        for (int i = 0; i <= MAX; i++) spf[i] = i;
        for (int i = 2; i * i <= MAX; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAX; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        // Union number with its prime factors
        for (int x : nums) {
            int val = x;
            unordered_set<int> primes;
            while (val > 1) {
                int p = spf[val];
                primes.insert(p);
                while (val % p == 0) val /= p;
            }
            for (int p : primes) {
                dsu.merge(x, p ); 
            }
        }

        // Check if all numbers are connected
        int root = dsu.find(nums[0]);
        for (int x : nums) {
            if (dsu.find(x) != root)
                return false;
        }
        return true;
    }
};
