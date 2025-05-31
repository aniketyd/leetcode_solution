class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mapa;

        for (int stone : stones) {
            mapa[stone] = unordered_set<int>();
        }

        mapa[0].insert(0);

        for (int stone : stones) {
            for (int k : mapa[stone]) {
                for (int i = k - 1; i <= k + 1; i++) {
                    if (i > 0 && mapa.find(stone + i) != mapa.end()) {
                        mapa[stone + i].insert(i);
                    }
                }
            }
        }


        return mapa[stones.back()].size();
    }
};