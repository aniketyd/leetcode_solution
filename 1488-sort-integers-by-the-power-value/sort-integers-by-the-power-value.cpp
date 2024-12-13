class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>v;
        for(int i=lo;i<=hi;i++){
            int n=i;
            int c=0;
            while(n>1){
                if(n%2==0)
                n/=2;
                else
                n=n*3+1;
                c++;
            }
            v.push_back({c,i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};