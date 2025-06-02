class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int minEle=nums[k];
        for(int i=k;i>=0;i--){
           minEle=min(minEle,nums[i]);
           nums[i]=minEle;
        }
        minEle=nums[k];
        int ans=0;
        for(int i=k;i<n;i++){
            minEle=min(minEle,nums[i]);
            nums[i]=minEle;
        }
        int j=k+1;
        for(int i=k;i>=0;i--){
             while(j<n&&nums[j]>=nums[i]){
                 ans=max(ans,(j-i)*nums[j]);
                j++;
             }
             ans=max(ans,(j-i)*nums[i]);
             
        }
         while(j<n){
                ans=max(ans,(j+1)*nums[j]);
                j++;
             }
      
return ans;
    }
};
//  1 3 3 7 4 4