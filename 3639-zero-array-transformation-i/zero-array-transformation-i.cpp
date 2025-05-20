class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int m=q.size();
        vector<int>pf(n+1);
        for(int i=0;i<m;i++){
            pf[q[i][0]]++;
            pf[q[i][1]+1]--;
        }
         if(pf[0]<nums[0])return false;
        for(int i=1;i<n;i++){
            pf[i]+=pf[i-1];
            if(pf[i]<nums[i])return false;
        }
        return true;
        
    }
};