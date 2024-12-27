class Solution {
public:
    bool canReach(string s, int mi, int ma) {
        int n=s.size();
        if(s[n-1]=='1')return false;
        vector<int>pf(n+1);
        
        for(int i=0;i<n;i++){
            if(i!=0)
            pf[i]+=pf[i-1];
         if(i==0||pf[i]>0&&s[i]=='0'){
           pf[min(i+mi,n)]++;
           pf[min(i+ma+1,n)]--;
         }
        }
        if(pf[n-1])
         return true;
         return false;
    }
};