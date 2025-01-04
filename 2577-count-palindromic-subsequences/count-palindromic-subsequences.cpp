class Solution {
public:
    int countPalindromes(string s) {
        int n=s.size();
        int mod=1e9+7;
        int ans=0;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                int sum=0;
                vector<int>mp(10),v(n),mp2(10);
                for(int k=n-1;k>=0;k--){
                    v[k]=sum;
                    int ch=s[k]-'0';
                    if(ch==j)
                    sum=(sum+mp[i])%mod;
                    mp[ch]++;
                }
            sum=0;
                for(int k=0;k<n;k++){
                    ans=(ans+(1LL*sum*v[k])%mod)%mod;
                    int ch=s[k]-'0';
                    if(ch==j)
                    sum=(sum+mp2[i])%mod;
                    mp2[ch]++;
                }
            }
        }
        return ans;
    }
};