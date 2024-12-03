class Solution {
public:
   
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)return 0;
        vector<int>mp(300);
        int ans=1;
        int j=0;
        for(int i=0;i<n;i++){
          while(mp[s[i]]==1){
            mp[s[j]]--;j++;
          }
          mp[s[i]]++;
          ans=max(ans,i-j+1);
        }
        return ans;
    }
};