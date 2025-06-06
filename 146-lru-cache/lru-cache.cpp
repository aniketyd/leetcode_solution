class LRUCache {
public:
    unordered_map<int,pair<int,int>>mp;
    int count=0;
    deque<pair<int,pair<int,int>>>q;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        put(key,mp[key].second);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.size()==n&&mp.find(key)==mp.end()){
            while(!q.empty()&&mp.find(q.front().first)!=mp.end()&&mp[q.front().first].first!=q.front().second.first){
             q.pop_front();
            }
            mp.erase(mp.find(q.front().first));
            q.pop_front();
        }
        mp[key]={count,value};
        q.push_back({key,{count,value}});
        count++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */