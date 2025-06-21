class Solution {
public:
vector<int> helper(vector<int>&nums,int k){
        deque<int>q;
        int n=nums.size();
        int d=n-k+1;
        for(int i=0;i<d-1;i++){
           while(!q.empty()&&nums[q.back()]>nums[i]){
            q.pop_back();
           }
           q.push_back(i);
        }
        vector<int>ans;
        for(int i=d-1;i<n;i++){
             while(!q.empty()&&nums[q.back()]>nums[i]){
            q.pop_back();
           }
           q.push_back(i);
           ans.push_back(nums[q.front()]);
           q.pop_front();
        }
        return ans;
    }
    vector<int> mostCompetitive(vector<int>& nums, int k) {
     return helper(nums,k);   
    }
};