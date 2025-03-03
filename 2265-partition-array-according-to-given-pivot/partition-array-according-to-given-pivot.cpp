class Solution {
public:
 
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int c=0;
        vector<int>ans(n);
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[j++]=nums[i];
            }
            else if(nums[i]==pivot)
            c++;
        }
        for(int i=0;i<c;i++)
        ans[j++]=pivot;
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                ans[j++]=nums[i];
            }
        }
        return ans;
    }
};