class FreqStack {
private:
    unordered_map<int, int> freq;               // val -> frequency
    unordered_map<int, stack<int>> group;       // frequency -> stack of values
    int maxFreq = 0;

public:
    FreqStack() {}

    void push(int val) {
        freq[val]++;
        int f = freq[val];
        group[f].push(val);
        if (f > maxFreq) maxFreq = f;
    }

    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if (group[maxFreq].empty()) maxFreq--;
        return val;
    }
};