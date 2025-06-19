class Solution {
public:
// 4 1 5 2 6
    int longestNonDecSub(vector<int>&nums){
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            if(v.empty()||v.back()<=nums[i])
            v.push_back(nums[i]);
            else{
                int indx=upper_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[indx]=nums[i];
            }
        }
        return (int)v.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<k;i++){
            vector<int>temp;
            for(int j=i;j<n;j+=k){
                temp.push_back(arr[j]);
            }
            ans+=(int)temp.size()-longestNonDecSub(temp);
        }
        return ans;
    }
};