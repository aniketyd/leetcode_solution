class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        int q = queries.size(); 
        vector<int> answers, inci(n);
        map<pair<int, int>, int> mp;
        for (auto& e: edges){
            e[0] -= 1; e[1] -= 1;
            sort(e.begin(), e.end()); 
        }
        for (int i = 0; i < edges.size(); i++){
            auto e = edges[i];
            inci[e[0]]++; 
            inci[e[1]]++;
            mp[{e[0], e[1]}] += 1;
        }
        
        vector<int> freq = inci;
        sort(freq.begin(), freq.end());
        for (int v: queries){
            int cnt = 0; 
            for (int i = 0, j = n - 1; i < n; i++){
                while (j >= 0 and freq[i] + freq[j] > v) j --;
                cnt += n - j - 1;
                if (inci[i] * 2 > v)
                    cnt -= 1;
            }
            cnt /= 2;
            for (auto& [p, f]: mp){
                if (inci[p.first] + inci[p.second] > v && inci[p.first] + inci[p.second] - f <= v){
                    cnt -= 1;
                }
            }
            answers.push_back(cnt);
        }
        return answers; 
    }
};