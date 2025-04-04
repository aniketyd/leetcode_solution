inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class RangeModule {
public:
    set<pair<int,int>> r;
    RangeModule() {
    }
    
    void addRange(int left, int right) {
        auto it = r.lower_bound({left, right});
        auto before = it;
        if(before!=r.begin()){
            before--;
            if(left<=before->second){
                left = min(left, before->first);
                right = max(before->second, right);
                r.erase(before);
            }
        }
        if(it!=r.end()){
            auto nxt = it;
            while(nxt!=r.end() && right>=nxt->first){
                right = max(nxt->second, right);
                auto b = nxt;
                nxt++;
                r.erase(b);
            }
        }
        r.insert(make_pair(left, right));
    }
    
    bool queryRange(int left, int right) {
        auto it = r.lower_bound({left, right});
        if(it!=r.end()){
            if(left>=it->first && right<=it->second){
                return true;
            }
        }
        if (!r.empty()){
            it--;
            if(left>=it->first && right<=it->second){
                return true;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        auto it = r.lower_bound({left, right});
        auto before = it;
        if(before!=r.begin()){
            before--;
            int n1, n2;
            //   30 -> 40
            // - 35 -> 45
            // - 35 -> 37
            if(left<before->second){
                int newright = min(left, before->second);
                if(newright>before->first){
                    r.insert(make_pair(before->first, newright));
                }
                if(right<before->second){
                    r.insert(make_pair(right, before->second));
                }
                r.erase(before);
            }
        }
        if(it!=r.end()){
            // 15->20, 30->40, 45->50
            // - 35->47
            // - 25->50
            // - 25->55
            // - 25->47
            auto nxt = it;
            int lastRight = -1;
            while(nxt!=r.end() && right>=nxt->first){
                lastRight = nxt->second;
                auto b = nxt;
                nxt++;
                r.erase(b);
            }
            if(right<lastRight){
                r.insert(make_pair(right, lastRight));
            }
        }
    }
};

