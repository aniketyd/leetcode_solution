class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int an=0;
        string ans="";
        for(int i=0;i<n;i++){
            int j=i-1,k=i+1;
            int c=1;
            while(j>=0&&k<n&&s[j]==s[k]){
               j--;k++; 
                c+=2;
            }
            if(c>an){
                ans="";
                for(int m=j+1;m<k;m++)
                ans+=s[m];
                an=c;
            }
             j=i,k=i+1;
            c=0;
            while(j>=0&&k<n&&s[j]==s[k]){
               j--;k++; 
                c+=2;
            }
            if(c>an){
                ans="";
                for(int m=j+1;m<k;m++)
                ans+=s[m];
                an=c;
            }
        }
        return ans;
    }
};