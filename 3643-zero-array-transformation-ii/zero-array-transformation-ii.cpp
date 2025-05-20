class Solution {
public:
    bool fun(vector<int>&nums,vector<vector<int>>&q,int mid){
        int n=nums.size();
        int m=q.size();
        vector<int>pf(n+1);
        for(int i=0;i<mid;i++){
            pf[q[i][0]]+=q[i][2];
            pf[q[i][1]+1]-=q[i][2];
        }
        for(int i=1;i<=n;i++){
            pf[i]+=pf[i-1];
        }
        for(int i=0;i<n;i++){
            if(pf[i]<nums[i])return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       int n=nums.size();
       int low=0,high=queries.size();
       int ans=-1;
       while(low<=high){
        int mid=(low+high)/2;
        if(!fun(nums,queries,mid)){
            
            low=mid+1;
        }
        else{ans=mid;
        high=mid-1;}
       }
       return ans;
    }
};