class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=0;
        deque<int>q;
        for(int i=0;i<n;i++){
            if(q.size()>0)
             ans=max(ans,q.front()-i+values[q.front()]+values[i]);
            while(!q.empty()&&q.back()-i+values[q.back()]<=values[i]){
                q.pop_back();
            }
             q.push_back(i);
        }
        return ans;
    }
};