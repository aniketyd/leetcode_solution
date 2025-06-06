class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0;  // max repeating character count in current window
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // Increment count of current character
            count[s[right] - 'A']++;
            
            // Update maxCount if current character's count is greater
            maxCount = max(maxCount, count[s[right] - 'A']);
            
            // If the number of characters to change (window size - maxCount) > k,
            // move the left pointer forward
            while (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            // Update the maximum length of the window
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};