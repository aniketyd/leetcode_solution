class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        int n=s.size();
        vector<int>mp(27,0);
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        int c=0;
        for(int i=0;i<26;i++)
        if(mp[i]%2==1)
        c++;
        if(c>k)return false;
        return true;
    }
};