class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(n==k)return 0LL;
        vector<long long>v;
        for(int i=1;i<n;i++){
            v.push_back(weights[i]+weights[i-1]);

        }
        sort(v.begin(),v.end());
        long long sum1=0,sum2=0;
        for(int i=0;i<k-1;i++){
            sum1+=v[i];
            sum2+=v[v.size()-1-i];
        }
        return sum2-sum1;
        
    }
};