
struct cmpMin{
    bool operator()(const pair<int,string>&v1,const pair<int,string>&v2){
        if(v1.first==v2.first)
          return v1.second<v2.second;
          return v1.first>v2.first;
    }
};
struct cmpMax{
    bool operator()(const pair<int,string>&v1,const pair<int,string>&v2){
        if(v1.first==v2.first)
          return v1.second>v2.second;
          return v1.first<v2.first;
    }
};

class SORTracker {
public:
    priority_queue<pair<int,string>,vector<pair<int,string>>,cmpMin>minHeap;
    priority_queue<pair<int,string>,vector<pair<int,string>>,cmpMax>maxHeap;
    int minHeapSize;
    SORTracker() {
        minHeapSize=1;
    }
    
    void add(string name, int score) {
        minHeap.push({score,name});
        if(minHeap.size()>minHeapSize){
            maxHeap.push({minHeap.top().first,minHeap.top().second});
            minHeap.pop();
        }
    }
    
    string get() {
        minHeapSize++;
        auto ans=minHeap.top();
        if(!maxHeap.empty()){
        minHeap.push({maxHeap.top().first,maxHeap.top().second});
        maxHeap.pop();
        }
        return ans.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */