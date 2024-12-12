class Solution {
public:
    int halveArray(vector<int>& g) {
        double sum = 0, tsum = 0;
        priority_queue<double> pq;
        
        for (int num : g) {
            sum += num; 
            pq.push(num * 1.0);
        }
        
        double target = sum / 2;
        int k = 0;
        
        while (tsum < target) {
            double t = pq.top();
            pq.pop();
            tsum += t / 2;
            pq.push(t / 2);
            k++;
        }
        
        return k;
    }
};
