class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& qu) {
        int n=nums.size();
        vector<int>v(n);
        int c=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]%2==nums[i]%2)
            c++;
            v[i]=c;
        }
        int q=qu.size();
        vector<bool>ans(q);
        for(int i=0;i<q;i++){
            int dif=v[qu[i][1]]-v[qu[i][0]];
            if(dif==0)
            ans[i]=true;
            else
            ans[i]=false;
        }
        return ans;
    }
};