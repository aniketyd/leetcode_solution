class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
       multiset<pair<int,int>>st;
       int n=queries.size();
       for(int i=0;i<n;i++){
        st.insert({queries[i],i});
       } 
       int m=intervals.size();
       for(int i=0;i<m;i++){
        intervals[i][0]=intervals[i][1]-intervals[i][0]+1;
       }
       sort(intervals.begin(),intervals.end());
       vector<int>ans(n,-1);
       for(int i=0;i<m;i++){
            int l=intervals[i][1]-intervals[i][0]+1;
            int r=intervals[i][1];
            stack<pair<int,int>>tempStore;
            auto start=st.lower_bound({l,-1});
            auto end=st.upper_bound({r,1e9});
            for(auto it=start;it!=end;++it){
                tempStore.push(*it);
                ans[(*it).second]=intervals[i][0];
            }
            while(!tempStore.empty()){
                st.erase(st.find(tempStore.top()));
                tempStore.pop();
            }
       }
       return ans;
    }
};