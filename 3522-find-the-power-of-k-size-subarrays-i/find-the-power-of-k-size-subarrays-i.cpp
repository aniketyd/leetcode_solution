class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        vector<int>ans;
        for(int i=1;i<k;i++){
           if(nums[i]-1!=nums[i-1])
           cnt++;

        }
        int l=0,h=k-1;
        while(h<n){
            if(cnt==0)
            ans.push_back(nums[h]);
            else
            ans.push_back(-1);
            ++l;
            ++h;
            if(h==n)break;
            if(nums[l]-1!=nums[l-1])cnt--;
            if(nums[h]-1!=nums[h-1])cnt++;
        }
        return ans;
    }
};