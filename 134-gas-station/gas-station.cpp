class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int start = 0, currSurplus = 0, totalSurplus = 0;

    for (int i = 0; i < n; i++) {
        int gain = gas[i] - cost[i];
        currSurplus += gain;
        totalSurplus += gain;

        if (currSurplus < 0) {
            start = i + 1;
            currSurplus = 0;
        }
    }

    return (totalSurplus >= 0) ? start : -1;
}
};