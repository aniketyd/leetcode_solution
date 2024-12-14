class Solution {
public:
   long long fun(vector<int>&nums,int k){
    int n=nums.size();
    deque<int>d;
    deque<int>dq;
    int j=0;
    long long ans=0;
    for(int i=0;i<n;i++){
       while(j<n&&(d.empty()||nums[d.front()]-nums[dq.front()]<=k)){
       while(!d.empty()&&nums[d.back()]<=nums[j]){
         d.pop_back();
       }
        while(!dq.empty()&&nums[dq.back()]>=nums[j]){
         dq.pop_back();
       }
       d.push_back(j);
       dq.push_back(j);
       ++j;
}     
    if(nums[d.front()]-nums[dq.front()]>k)
    ans+=n-j+1;
       if(d.front()==i)
       d.pop_front();
       if(dq.front()==i)
       dq.pop_front();
    }
    return ans;
   }
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        ans=fun(nums,2);
        
        ans=1LL*n*(n+1)/2 -ans;
        return ans;
    }
};