 

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestSubarray(const vector<int>& nums, const int limit) {
    deque<int> maxDeque, minDeque;  // Store indices of nums for max/min
    int j = 0, ans = 1;

    for (int i = 0; i < nums.size(); i++) {
      while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[i]) maxDeque.pop_back();
      maxDeque.push_back(i);

      while (!minDeque.empty() && nums[minDeque.back()] >= nums[i]) minDeque.pop_back();
      minDeque.push_back(i);

      while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
        if (maxDeque.front() == j) maxDeque.pop_front();
        if (minDeque.front() == j) minDeque.pop_front();
        j++;
      }

      ans = max(ans, i - j + 1);
    }

    return ans;
  }
};