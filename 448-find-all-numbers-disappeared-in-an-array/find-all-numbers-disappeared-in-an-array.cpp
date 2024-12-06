class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        int indx=0;

        for(int i=0;i<n;i++){
            while(nums[i]>0&&nums[nums[i]-1]>0){
              if(nums[i]-1<=i)
              nums[nums[i]-1]=-1;
              else {
                int temp=nums[i]-1;
                swap(nums[i],nums[temp]);
                nums[temp]=-1;
              }
              
            }
           
        }
         vector<int>ans;
            for(int i=0;i<n;i++){
                if(nums[i]!=-1)
                ans.push_back(i+1);
            }
            return ans;
    }
};