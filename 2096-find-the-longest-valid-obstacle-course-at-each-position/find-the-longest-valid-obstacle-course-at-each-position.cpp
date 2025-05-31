class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        int n=o.size();
        vector<int>ans(n,1),v;
       for(int i=0;i<n;i++){
        int idx=upper_bound(v.begin(),v.end(),o[i])-v.begin();
        if(idx!=v.size()){
            v[idx]=o[i];
            ans[i]=idx+1;
        }
        else{
            v.push_back(o[i]);
            ans[i]=v.size();
        }
       }
       return ans;
    }
};