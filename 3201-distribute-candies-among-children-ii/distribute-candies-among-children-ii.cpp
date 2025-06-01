class Solution {
public:
 
    long long distributeCandies(int n, int limit) {
       
        
long long ans=0;
        for(int i=0;i<=limit;i++){
           if(n-i>=0){
            int s=n-i;
            if(s<=limit){
                ans+=i+1;
            }
            else{
                int initialPoint=s-limit;
               ans+=max(0LL,1LL*(limit-initialPoint+1));
            }
           }
           else break;
        }
        return ans;
    }
};