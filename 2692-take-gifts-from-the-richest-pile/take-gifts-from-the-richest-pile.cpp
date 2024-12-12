class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
     int n=g.size();
     long long sum=0;
     priority_queue<int>pq;
     for(int i=0;i<n;i++){
        pq.push(g[i]);
     }
     for(int i=0;i<k;i++){
        int t=pq.top();
        pq.pop();
        pq.push(floor(sqrt(t)));
     }
     while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
     }
     return sum;
    }
};