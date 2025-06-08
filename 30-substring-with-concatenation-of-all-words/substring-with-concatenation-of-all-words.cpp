class Solution {
public:
   vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if (words.empty() || s.empty()) return res;

    int wordLen = words[0].size();
    int wordCount = words.size();
    int totalLen = wordLen * wordCount;

    unordered_map<string, int> wordMap;
    for (string& word : words) wordMap[word]++;

    for (int i = 0; i < wordLen; ++i) {
        unordered_map<string, int> seen;
        int left = i, count = 0;

        for (int j = i; j + wordLen <= s.size(); j += wordLen) {
            string word = s.substr(j, wordLen);
            if (wordMap.count(word)) {
                seen[word]++;
                count++;

                while (seen[word] > wordMap[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }

                if (count == wordCount) {
                    res.push_back(left);
                }
            } else {
                seen.clear();
                count = 0;
                left = j + wordLen;
            }
        }
    }
    return res;
}
};