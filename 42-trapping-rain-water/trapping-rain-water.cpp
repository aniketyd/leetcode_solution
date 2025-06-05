class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        vector<int>ps(n,0);
        int m=0,m2=0;
        for(int i=0;i<n;i++)
        {
           
            m2=max(m2,v[n-1-i]);
            ps[n-1-i]=m2;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {   m=max(m,v[i]);
                 sum+=min(m,ps[i])-v[i];
        }
        return sum;
    }
};