class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0;
int ans=0,cnt=0;
        for(int i=0;i<n;i++){
            while((nums[i]==1&&cnt>k)||(nums[i]==0&&cnt>=k)){
               if(nums[j]==0) cnt--;j++;
            }
            if(nums[i]==0)
            cnt++;
            ans=max(ans,i-j+1);

        }
        return ans;
    }
};