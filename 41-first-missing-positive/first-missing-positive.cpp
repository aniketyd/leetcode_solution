class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        nums.push_back(-1);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];
          
            while(val>=0&&val<n&&nums[val]!=val){
                int nval=nums[val];
                nums[val]=val;
                val=nval;
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]!=i)
            return i;
        }
        return n;
    }
};