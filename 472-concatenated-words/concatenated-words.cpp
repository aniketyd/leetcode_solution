#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> result;

        for (const string& word : words) {
            if (word.empty()) continue;

            dict.erase(word);  // Avoid using the word itself
            unordered_map<int, bool> memo;  // Memoization by index
            if (canForm(word, 0, dict, memo)) {
                result.push_back(word);
            }
            dict.insert(word); // Reinsert for next iteration
        }

        return result;
    }

private:
    bool canForm(const string& word, int start, unordered_set<string>& dict, unordered_map<int, bool>& memo) {
        if (start == word.size()) return true;
        if (memo.count(start)) return memo[start];

        for (int end = start + 1; end <= word.size(); ++end) {
            string sub = word.substr(start, end - start);
            if (dict.count(sub)) {
                if (canForm(word, end, dict, memo)) {
                    memo[start] = true;
                    return true;
                }
            }
        }

        memo[start] = false;
        return false;
    }
};
