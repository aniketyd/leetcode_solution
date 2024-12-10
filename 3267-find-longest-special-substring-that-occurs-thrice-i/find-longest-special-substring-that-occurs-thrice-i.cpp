class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            string ss="";
            for(int j=i;j<n;j++){
                if(j>i){
                    if(s[j-1]!=s[j])break;
                }
            ss+=s[j];
            mp[ss]++;
            
            }
        }
        int mx=-1;
        for(auto val:mp){
            int k=val.first.size();
            if(val.second>=3)
            mx=max(mx,k);
        }
        return mx;
    }
};