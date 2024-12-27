class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});
        int ans=nums[0];
        for(int i=1;i<n;i++){
             while(!pq.empty()&&pq.top().second<i-k)
             pq.pop();
            ans=pq.top().first+nums[i];
            pq.push({ans,i});
        }
        return ans;
    }
};
