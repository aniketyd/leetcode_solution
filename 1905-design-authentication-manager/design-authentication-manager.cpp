class AuthenticationManager {
public:
    int timeToLive;
    unordered_map<string, int> mp;
    
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if (mp[tokenId] > currentTime) mp[tokenId] = currentTime + timeToLive;
        else mp[tokenId] = 0;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto x: mp) {
            if (x.second > currentTime) ans++;
        }
        return ans;
    }
};

