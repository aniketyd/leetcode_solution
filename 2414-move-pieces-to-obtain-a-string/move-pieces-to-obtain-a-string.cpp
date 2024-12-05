class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        vector<pair<char,int>>v,b;
        for(int i=0;i<n;i++){
            if(start[i]!='_')v.push_back({start[i],i});
            if(target[i]!='_')b.push_back({target[i],i});
        }
        if(b.size()!=v.size())return false;
        
        for(int i=0;i<v.size();i++){
            if(v[i].first!=b[i].first)return false;
            if(v[i].first=='L'&&b[i].second>v[i].second)return false;
             if(v[i].first=='R'&&b[i].second<v[i].second)return false;
        }
        return true;
    }
};