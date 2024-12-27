class Solution {
public:
   int mp(vector<int>&nums,int i,int j){
       int prod=1;
       for(int k=i;k<=j;k++){
        prod*=nums[k];
       }
       if(prod>0)return prod;
       int p1=prod,p2=prod;
       
       while(p1<0){
        p1/=nums[i];
        i++;
       }
       
       while(p2<0){
        p2/=nums[j];
        --j;
       }
       return max(p1,p2);
   }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int i1=-1,j1=-1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                if(i1==-1)
                i1=i;
                j1=i;
            }
            else{
                if(i1!=-1&&j1!=-1&&i1<j1){
                    ans=max(ans,mp(nums,i1,j1));
                }
                else if(i1==j1&&i1!=-1)
                ans=max(ans,nums[i1]);
                i1=-1,j1=-1;
                ans=max(ans,0);
            }
        }
         if(i1!=-1&&j1!=-1&&i1<j1){
                    ans=max(ans,mp(nums,i1,j1));
                }
                else if(i1==j1&&i1!=-1)
                ans=max(ans,nums[i1]);
                i1=-1,j1=-1;
                return ans;
    }
};