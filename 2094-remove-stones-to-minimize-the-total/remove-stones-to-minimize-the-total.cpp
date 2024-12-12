class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int total = accumulate(piles.begin(), piles.end(), 0);
        for (int i=0; i<k; ++i) {
            int cur = pq.top();
            if (cur==1) break;
            pq.pop();
            int remove = cur/2;
            cur -= remove;
            total -= remove;
            pq.push(cur);
        }
        return total;
    }
};