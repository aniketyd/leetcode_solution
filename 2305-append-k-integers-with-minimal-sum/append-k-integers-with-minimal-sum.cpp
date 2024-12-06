class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back(0);
        int n=nums.size();
        long long sum=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            int d=nums[i]-nums[i-1];
          if(nums[i]-nums[i-1]>1){
            if(k-d+1>=0){
             k-=d-1;
             nums[i]-=1;
              long long res=(1LL*nums[i]*(nums[i]+1)/2)-(1LL*nums[i-1]*(nums[i-1]+1)/2);
              nums[i]+=1;
              sum+=res;
            }
            else{
                 
                  nums[i]=nums[i-1]+k; k=0;
              long long res=(1LL*nums[i]*(nums[i]+1)/2)-(1LL*nums[i-1]*(nums[i-1]+1)/2);
              sum+=res;
              return sum;
            }
          }
        }
        int num=nums[n-1]+k;
         long long res=(1LL*num*(num+1)/2)-(1LL*nums[n-1]*(nums[n-1]+1)/2);
              sum+=res;
              return sum;
    }
};