class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1,ans=-1;
        while(l<=h){
           int mid=(l+h)/2;
           if(nums[mid]<target){l=mid+1;ans=mid;}
           else
           h=mid-1;
        }
        return ans+1;
    }
};