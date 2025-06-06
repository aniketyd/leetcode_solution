class LFUCache {
public:
    unordered_map<int,tuple<int,int,int>>mp;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int n;
    int id=0;
    LFUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        put(key,get<1>(mp[key]));
        return get<1>(mp[key]);
    }
    
    void put(int key, int value) {
        if(mp.size()==n&&mp.find(key)==mp.end()){
            while(get<0>(mp[(pq.top().second.second)])!=pq.top().second.first){
                pq.pop();
            }
            mp.erase(mp.find(pq.top().second.second));
            pq.pop();
        }
        mp[key]=make_tuple(id,value,get<2>(mp[key])+1);
        pq.push({get<2>(mp[key]),{id,key}});
        id++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */