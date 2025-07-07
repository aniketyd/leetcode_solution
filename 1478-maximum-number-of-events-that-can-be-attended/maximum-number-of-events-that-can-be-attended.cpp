class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int mxDay=0,cnt=0;
        for(int i=0;i<n;i++){
            mxDay=max(mxDay,events[i][1]);
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        int j=0;
        for(int i=1;i<=mxDay;i++){
               while(j<n&&events[j][0]<=i){
                pq.push(events[j][1]);
                j++;
               }
               while(!pq.empty()&&pq.top()<i){
                pq.pop();
               }
               if(!pq.empty()){
                pq.pop();
                cnt++;
               }   
        }
        return cnt;
    }
};