class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int balance = 0;

        // First pass: treat '*' as '('
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '*') {
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) // this means we had more ')' than '(' + '*' combined
                return false;
        }

        // Second pass: treat '*' as ')'
        balance = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || s[i] == '*') {
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) // this means we had more '(' than ')' + '*' combined
                return false;
        }

        return true;
    }
};