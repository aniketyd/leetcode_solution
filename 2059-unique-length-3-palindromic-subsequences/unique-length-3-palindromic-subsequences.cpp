class Solution {
public:
    int fun(int i){
        int c=0;
        while(i>0){
            if(i%2==1)c++;
            i/=2;
        }
        return c;
    }
    int countPalindromicSubsequence(string s) {
        int n=s.size();int ans=0;
        for(int i=0;i<26;i++){
           int k=0;char ch='a'+i;
           while(k<n&&s[k]!=ch)k++;
           int j=n-1;
           while(j>=0&&s[j]!=ch)j--;
           int msk=0;
          for(int t=k+1;t<=j-1;t++){
              msk|=(1<<s[t]-'a');
          }
           ans+=fun(msk);
        }
        return ans;
    }
};