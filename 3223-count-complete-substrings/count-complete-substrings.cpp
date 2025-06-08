class Solution {
public:
    int countCompleteSubstrings(const string &w, int k) {
    int res = 0;
    for (int chars = 1; chars <= min((int)w.size() / k, 26); ++chars) {
        int cnt[26] = {}, exact = 0, sz = chars * k;
        for (int i = 0, j = 0; i < w.size(); ++i) {
            if (i && (abs(w[i] - w[i - 1]) > 2)) {
                memset(cnt, 0, sizeof(cnt));
                exact = 0;
                j = i;
            }
            int reps = ++cnt[w[i] - 'a'];
            exact += reps == k ? 1 : reps == k + 1 ? -1 : 0;
            if (i - j + 1 >= sz) {
                if (i - j >= sz) {
                    int reps = --cnt[w[j++] - 'a'];
                    exact += reps == k ? 1 : reps == k - 1 ? -1 : 0;
                }
                res += exact == chars;
            }
        }
    }
    return res;
}
};