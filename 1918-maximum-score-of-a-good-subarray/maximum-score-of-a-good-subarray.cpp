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
            auto greaterElements=lower_bound(nums.begin(),nums.begin()+k,minEle)-(nums.begin()+k);
            greaterElements=abs(greaterElements);
            int possAns=(greaterElements+(i-k+1))*minEle;
            ans=max(ans,possAns);
        }
        for(int i=k;i>=0;i--){
            minEle=nums[i];
            int greaterElements = n-k-1;
auto it = lower_bound(nums.begin() + k + 1, nums.end(), minEle, greater<int>());
if (it != nums.end()) {
   
    greaterElements = it - (nums.begin() + k+1);
}
        
            int possAns=(greaterElements+(k-i+1))*minEle;
            ans=max(ans,possAns);
        }
        for(int i=0;i<n;i++){
            cout<<nums[i]<<' ';
        }
       
return ans;
    }
};
//  1 3 3 7 4 4