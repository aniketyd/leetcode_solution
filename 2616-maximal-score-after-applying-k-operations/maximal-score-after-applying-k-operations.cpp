class Solution {
public:
    long long maxKelements(vector<int>& g, int k) {
           int n=g.size();
     long long sum=0;
     priority_queue<int>pq;
     for(int i=0;i<n;i++){
        pq.push(g[i]);
     }
     for(int i=0;i<k;i++){
        int t=pq.top();
        sum+=t;
        pq.pop();
        pq.push(ceil(t*1.0/3));
     }
   
     return sum;
    }
};