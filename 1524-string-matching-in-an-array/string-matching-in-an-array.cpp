class Solution {
public:

    void constructLps(string &pat, vector<int> &lps) {

    // len stores the length of longest prefix which
    // is also a suffix for the previous index
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {

        // If characters match, increment the size of lps
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else {
            if (len != 0) {

                // Update len to the previous lps value
                // to avoid reduntant comparisons
                len = lps[len - 1];
            }
            else {

                // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}
bool fun(string &pat, string &txt,vector<int>&lps) {
    int n = txt.length();
    int m = pat.length();
    int i = 0;
    int j = 0;

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                return true;
                j = lps[j - 1];
            }
        }
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
}
bool search(vector<string>&word, string &pat) {
    int n = word.size();
    int m = pat.length();
    vector<int> lps(m);
    constructLps(pat, lps);
    for(int i=0;i<n;i++){
        if(pat!=word[i]){
            if(fun(pat,word[i],lps))return true;
        }
    }
    return false;
    
}
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(search(words,words[i]))
            ans.push_back(words[i]);
        }
        return ans;
    }
};