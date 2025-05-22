class Solution {
    vector<string> res; // Stores the valid results
    int maxLen = 0; // Tracks the length of the longest valid string

    // Function to check if a string is valid
    bool isValid(const string &s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }

    void backtrack(string s, int start) {
        // If the string is valid, consider adding it to the results
        if (isValid(s)) {
            if (s.size() >= maxLen) {
                if (s.size() > maxLen) {
                    res.clear(); // Clear shorter valid strings
                    maxLen = s.size();
                }
                if (find(res.begin(), res.end(), s) == res.end()) {
                    res.push_back(s); // Avoid duplicate entries in results
                }
            }
            return;
        }

        // Try removing each character
        for (int i = start; i < s.size(); i++) {
            // Skip duplicates
            if (i > start && s[i] == s[i - 1]) continue;

            // Only attempt removal on parentheses
            if (s[i] == '(' || s[i] == ')') {
                string next = s.substr(0, i) + s.substr(i + 1);
                backtrack(next, i); // Move forward with the modified string
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        res.clear();
        maxLen = 0;

        // Start backtracking
        backtrack(s, 0);

        return res;
    }
};