class Solution {
public:
    int fun(string &s,int i, int j){
        int c=0;
        if(i>j)return 0;

        vector<int>mp(27,0);
        for(i;i<=j;i++){
          mp[s[i]-'a']++;
        }
        for(int k=0;k<26;k++)
        if(mp[k]>0)c++;
        return c;
    }
    int countPalindromicSubsequence(string s) {
        int n=s.size();int ans=0;
        for(int i=0;i<26;i++){
           int k=0;char ch='a'+i;
           while(k<n&&s[k]!=ch)k++;
           int j=n-1;
           while(j>=0&&s[j]!=ch)j--;
          
           ans+=fun(s,k+1,j-1);
        }
        return ans;
    }
};