#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* next[26];
        int index;
        vector<int> list;

        TrieNode() {
            index = -1;
            for (int i = 0; i < 26; ++i) next[i] = nullptr;
        }
    };

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        TrieNode* root = new TrieNode();

        for (int i = 0; i < words.size(); ++i) {
            addWord(root, words[i], i);
        }

        for (int i = 0; i < words.size(); ++i) {
            search(words, i, root, res);
        }

        return res;
    }

private:
    void addWord(TrieNode* root, const string& word, int index) {
        for (int i = word.size() - 1; i >= 0; --i) {
            int j = word[i] - 'a';
            if (root->next[j] == nullptr) {
                root->next[j] = new TrieNode();
            }
            if (isPalindrome(word, 0, i)) {
                root->list.push_back(index);
            }
            root = root->next[j];
        }
        root->list.push_back(index);
        root->index = index;
    }

    void search(vector<string>& words, int i, TrieNode* root, vector<vector<int>>& res) {
        const string& word = words[i];
        for (int j = 0; j < word.size(); ++j) {
            if (root->index >= 0 && root->index != i && isPalindrome(word, j, word.size() - 1)) {
                res.push_back({i, root->index});
            }
            root = root->next[word[j] - 'a'];
            if (root == nullptr) return;
        }
        for (int j : root->list) {
            if (i == j) continue;
            res.push_back({i, j});
        }
    }

    bool isPalindrome(const string& word, int i, int j) {
        while (i < j) {
            if (word[i++] != word[j--]) return false;
        }
        return true;
    }
};
