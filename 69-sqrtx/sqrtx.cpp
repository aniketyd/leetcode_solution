class Solution {
public:
    int mySqrt(int x) {
       int low=0,high=(1<<18);
       int ans;
       while(low<=high){
        int mid=low+(high-low)/2;
        long long res=1LL*mid*mid;
        if(res<=x){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
       }
       return ans;
    }
};