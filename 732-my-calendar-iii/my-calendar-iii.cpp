class MyCalendarThree {
public:
    map<int, int> hash;

    MyCalendarThree() {}

    int book(int start, int end) {
        hash[start]++;
        hash[end]--;

        int ongoing = 0;
        int maxBooking = 0;
        for (auto it : hash) {
            ongoing += it.second;
            maxBooking = max(maxBooking, ongoing);
        }

        return maxBooking;
    }
};