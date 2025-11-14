class Solution {
public:
 int subarraySum(vector<int>& nums, int k) {
    long long sum = 0;
    long long ans = 0;
    unordered_map<long long,int> freq;
    freq[0] = 1;
    for (int x : nums) {
        sum += x;
        auto it = freq.find(sum - k);
        if (it != freq.end()) ans += it->second;
        ++freq[sum];
    }
    return (int)ans;
}
};