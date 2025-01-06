class Solution {
public:
    vector<int> minOperations(string b) {
        int n=b.size();
        vector<int>ans(n);
        int c=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=c;
            ans[i]=sum;
            if(b[i]=='1')
            c++;
        }
        c=0,sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=c;
            ans[i]+=sum;
            if(b[i]=='1')
            c++;
        }
        return ans;
    }
};