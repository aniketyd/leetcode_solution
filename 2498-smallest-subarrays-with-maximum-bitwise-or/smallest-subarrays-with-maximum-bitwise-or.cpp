class Solution {
public:
   int fun(vector<int>&v){
    int val=0;
    int i=0;
    while(i<34){
        if(v[i]>0)
        val+=(1<<i);i++;
    }
    return val;
   }
    void fun2(vector<int>&v,int val,int f){
    int i=0;
    while(val>0){
        if(val%2==1&&f)
        v[i]++;
        else if(val%2==1&&(!f))
        v[i]--;
        i++;
        val/=2;
    }
   
   }
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>pf(n);
        int a=0;
        for(int i=n-1;i>=0;i--){
            a=a|nums[i];
            pf[i]=a;
        }
        a=0;
        vector<int>v(40),ans(n);
        int j=0;
        for(int i=0;i<n;i++){
           while(j<n&&pf[i]!=fun(v)){
            fun2(v,nums[j],1);
            j++;
           }
           ans[i]=j-i;
           if(ans[i]<=0)ans[i]=1;
           fun2(v,nums[i],0);
        }
        return ans;
    }
};