class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if((nums[i]^k)>nums[i])count++;
        }
        long long sumNodes=0;

        if(count%2==0){
            for(int i=0;i<n;i++){
                sumNodes+=max(nums[i]^k,nums[i]);
            }
            
            return sumNodes;
        }
        int mi=1e9,mx=-1e9;
        for(int i=0;i<n;i++){
            if((nums[i]^k)>nums[i]){
                mi=min(mi,(nums[i]^k)-nums[i]);
            }
            else{
                mx=max(mx,(nums[i]^k)-nums[i]);
            }
             sumNodes+=max(nums[i]^k,nums[i]);
        }
        if(mx==-1e9)
        return (sumNodes-mi);
        if(mi>abs(mx)){
            sumNodes-=abs(mx);
        }
        else{
            sumNodes-=mi;
        }
        return sumNodes;

    }
};