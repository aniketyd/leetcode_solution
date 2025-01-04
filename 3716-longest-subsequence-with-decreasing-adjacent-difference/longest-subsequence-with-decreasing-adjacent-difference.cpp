class Solution {
public:
    int longestSubsequence(vector<int>& v) {
        int n = v.size();
        
       
        vector<vector<int>> dp(305, vector<int>(305, 0));  
        int ans = 1;  
        
        for (int i = 0; i < n; i++) {
             vector<int>dd(305);
             for(int d=300;d>=0;d--){
                dd[d]=dp[v[i]][d];
            }
            for (int diff = 300; diff >= 0; diff--) {
               
                dd[diff]=max(dd[diff],dd[diff+1]);
                   if (v[i] +diff <=304) {
                    dd[diff] = max(dd[diff], dp[v[i] +diff][diff] + 1);
                }
                else{
                    dd[diff]=max(dd[diff],1);
                }
                if (v[i] - diff >= 0) {
                    dd[diff] = max(dd[diff], dp[v[i] - diff][diff] + 1);
                }
                else{
                    dd[diff]=max(dd[diff],1);
                }
                
                ans = max(ans, dd[diff]);
          
            }
            for(int d=300;d>=0;d--){
                dp[v[i]][d]=dd[d];
            }
        }
        
        
        return ans;
    }
};