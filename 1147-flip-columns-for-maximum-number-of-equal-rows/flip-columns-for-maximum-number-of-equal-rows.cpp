class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string s="",s2="";
            for(int j=0;j<m;j++){
              if(mat[i][j]==1){s+='1';s2+='0';}
              else
             { s+='0';s2+='1';}
            }
            mp[s]++;mp[s2]++;
        }
        int ans=0;
        for(auto val:mp){
            ans=max(ans,val.second);
        }
        return ans;
    }
};