class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        if(k>0)reverse(code.begin(),code.end());
        int t=k;
        k=abs(k);
        vector<int>v,ans;
        for(int i=0;i<2*n;i++){
            v.push_back(code[i%n]);
        }
        int sum=0;
        for(int i=n-1;i>n-1-k;i--){
            sum+=v[i];
        }
        for(int i=n;i<2*n;i++){
            ans.push_back(sum);
            sum-=v[i-k];
            sum+=v[i];
        }
        if(t>0)reverse(ans.begin(),ans.end());
        return ans;
    }
};