class Solution {
public:
    long long minEnd(int n, int x) {
     --n;
       vector<int>v;
       int k=n;
       while(k>0){
        v.push_back(k%2);
        k/=2;
       } 
    
    long long ans=x;
    int i=0,c=0;
    while(i<v.size()){
       if(x%2==0){
          ans+=1LL*v[i]*1LL*(1LL<<c);
          i++;
       }
       x/=2;
       c++;
    }
    return ans;
    }
};