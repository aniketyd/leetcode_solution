class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int ans=0;
        int m=fruits[0].size();
        for(int i=0;i<n;i++){
            ans+=fruits[i][i];fruits[i][i]=0;
        }
        vector<vector<int>>v1(n,vector<int>(m,-1e9)),v2(n,vector<int>(m,-1e9));
        v1[0][n-1]=fruits[0][n-1];
        v2[n-1][0]=fruits[n-1][0];
        for(int i=1;i<n;i++){
             for(int j=n-1;j>=(n-1-i);j--){
                  int mx=0;
                   if(j+1<n)
                    mx=v1[i-1][j+1];
                    if(v1[i-1][j]!=-1e9)
                    mx=max(mx,v1[i-1][j]);
                    if(j-1>=0&&v1[i-1][j-1]!=-1e9)
                    mx=max(mx,v1[i-1][j-1]);
                    v1[i][j]=mx+fruits[i][j];
             }
        }
        for(int i=1;i<n;i++){
             for(int j=n-1;j>=(n-1-i);j--){
                  int mx=0;
                    if(j+1<n)
                    mx=v2[j+1][i-1];
                    if(v2[j][i-1]!=-1e9)
                    mx=max(mx,v2[j][i-1]);
                    if(j-1>=0&&v2[j-1][i-1]!=-1e9)
                    mx=max(mx,v2[j-1][i-1]);
                    v2[j][i]=mx+fruits[j][i];
             }
        }
        return ans+v2[n-1][n-1]+v1[n-1][n-1];
    }
};