class AuthenticationManager {
public:
    
    // universal lifetime 
    int lifeTime;
    
    // record the token id and lifetime with unique id
    unordered_map<string,pair<int,int>>records;
    
    // unique incremental id of tokens
    int tokenCount;
    
    // store the lifetime of tokens MSB = lifetime, LSB = unique id
    set<long long>tokenLife;
    
    AuthenticationManager(int timeToLive) {
        
        lifeTime = timeToLive;
        tokenCount = 1;
    }
    
    // Add new token uniqueId and lifetime in hash table and Set
    void generate(string tokenId, int currentTime) {
        
        long long alive = currentTime + lifeTime;
        long long id = tokenCount;
        records[tokenId] = {currentTime + lifeTime,tokenCount};
        tokenLife.insert(alive<<32 | id);
        tokenCount++;
    }
    
    void renew(string tokenId, int currentTime) {
        
        //Check if tokenId exist in hash table and lifetime > current time
        // Remove the previous lifetime from Set and update Set
        // and hash table with updated lifetime
        if(records.count(tokenId) && records[tokenId].first>currentTime)
        {
            long long id = records[tokenId].second;
            long long alive = records[tokenId].first;
            tokenLife.erase(tokenLife.find(alive<<32 | id));
            alive = currentTime + lifeTime;
            records[tokenId].first = currentTime + lifeTime;
            tokenLife.insert(alive<<32 | id);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        
        // add tokenCount with current time as current time can be a expire time as well
        long long time = currentTime;        
        time = time<<32 | (long long)tokenCount;
        
        // search distance from begin to upper bound of target time => expired tokens
        int expired = distance(tokenLife.begin(),tokenLife.upper_bound(time));
        
        // total tokens - expired tokens
        return tokenLife.size() - expired;
    }
};