class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        stations.push_back({target,0});
        int n=stations.size();
        int count=0;
        for(int i=0;i<n;i++){
            while(!pq.empty()&&startFuel<stations[i][0]){
                startFuel+=pq.top();
                pq.pop();
                count++;
            }
            if(startFuel<stations[i][0])return -1;
            pq.push(stations[i][1]);
        }
        return count;
    }
};