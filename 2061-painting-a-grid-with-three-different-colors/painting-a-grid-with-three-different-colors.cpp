class Solution {
public:
    int colorTheGrid(int m, int n) {
       vector<vector<int>>dp(pow(3,m),vector<int>(n));
        int mod=1e9+7;
       unordered_map<int,vector<int>>mp;
       for(int i=0;i<(int)(pow(3,m));i++){
        int val=i;
        vector<int>temp;
        int prev=-1,f=1;
        int c=0;
        while(c<m){
            temp.push_back(val%3);
            if(temp.back()==prev){
                f=0;
                break;
            }
            c++;
            prev=temp.back();
            val/=3;
        }
        if(f)
       { mp[i]=temp;dp[i][0]=1;}
        
       }
       
       for(int i=1;i<n;i++){
         for(auto &[m1,temp1]:mp){
            for(auto &[m2,temp2]:mp){
                int f=1;
                for(int j=0;j<temp1.size();j++){
                    if(temp1[j]==temp2[j]){f=0;break;}
                }
                if(f){
                    dp[m1][i]=(dp[m1][i]+dp[m2][i-1])%mod;
                }
            }
         }
       }
       int ans=0;
       for(int i=0;i<pow(3,m);i++)
       ans=(ans+dp[i][n-1])%mod;
       return ans;
       
    }
};