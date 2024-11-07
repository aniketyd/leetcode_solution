class Solution {
public:
    int largestCombination(vector<int>& cand) {
        int n=cand.size();
        vector<int>v(32);
        for(int i=0;i<n;i++){
           int k=cand[i];
           int c=0;
           while(k>0){
            if(k%2==1)
            v[c]++;
            k/=2;
            c++;
           }
        }
        int mx=-1;
        for(int i=0;i<32;i++){
            mx=max(mx,v[i]);
        }
        return mx;
    }
};