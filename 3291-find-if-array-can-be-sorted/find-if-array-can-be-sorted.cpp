class Solution {
public:
    int bitcount(int k){
        int count=0;
        while(k>0){
            if(k%2==1)
            count++;
            k/=2;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        int b=0,prevmx=-1,mx=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int bc=bitcount(nums[i]);
            if(bc!=b){
                prevmx=mx;
            }
            
            if(nums[i]<prevmx)return false;
            mx=max(mx,nums[i]);
            b=bc;
        }
        return true;
    }
};