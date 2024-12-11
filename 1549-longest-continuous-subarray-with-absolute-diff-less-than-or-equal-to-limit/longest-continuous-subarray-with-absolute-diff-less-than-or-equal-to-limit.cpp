class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int>dq,ddq;
        int ans=-1;
        int j=0;
        for(int i=0;i<n;i++){
 while(dq.size()>0&&dq.front()<i)
            dq.pop_front();
            while(ddq.size()>0&&ddq.front()<i)
            ddq.pop_front();

            while(j<n&&(dq.empty()||nums[dq.front()]-nums[ddq.front()]<=limit)){
            while(dq.size()>0&&nums[dq.back()]<=nums[j]){
                dq.pop_back();
            }
            while(ddq.size()>0&&nums[ddq.back()]>=nums[j]){
                ddq.pop_back();
            }
           
            dq.push_back(j);
            ddq.push_back(j);
            ++j;
            }
            if(j==n&&nums[dq.front()]-nums[ddq.front()]<=limit)
            ans=max(ans,j-i);
            ans=max(ans,j-i-1);
            cout<<i<<' '<<ans<<' '<<j<<endl;
           
            
        }
        return ans;
    }
};