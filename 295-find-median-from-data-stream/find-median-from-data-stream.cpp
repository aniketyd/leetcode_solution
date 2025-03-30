class MedianFinder {
public:
    // low stores the lower half (largest element at rbegin())
    multiset<int> low;
    // high stores the upper half (smallest element at begin())
    multiset<int> high;
    double median;
    
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        // Insert the new number into the correct multiset.
        if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
        } else {
            high.insert(num);
        }
        
        // Rebalance: if one set has more than one extra element, move one element.
        if (low.size() > high.size() + 1) {
            // Move the largest element from low to high.
            auto it = low.end();
            it--;
            high.insert(*it);
            low.erase(it);
        } else if (high.size() > low.size() + 1) {
            // Move the smallest element from high to low.
            auto it = high.begin();
            low.insert(*it);
            high.erase(it);
        }
        
        // Compute the median.
        if (low.size() == high.size()) {
            median = ((double)*low.rbegin() + *high.begin()) / 2.0;
        } else if (low.size() > high.size()) {
            median = *low.rbegin();
        } else {
            median = *high.begin();
        }
    }
    
    double findMedian() {
        return median;
    }
};
