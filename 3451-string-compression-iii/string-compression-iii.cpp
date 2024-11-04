class Solution {
public:
    string compressedString(string s) {
        string ans="";
        int n=s.size();
        int c=1;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                ans+='0'+c;
              ans+=s[i-1];
                c=1;
            }
            else if(c==9){
                ans+='9';
                ans+=s[i-1];
                c=1;
            }
            else c++;
        }
        ans+='0'+c;
         ans+=s[n-1];
        return ans;
    }
};