class Solution {
public:
    string getSmallestString(int n, int k) {
        int index=1;
        string s(n,'a');
         k-=n;
         int i;
         for( i=s.size()-1;i>=0 && k>=26;i--){
             s[i]='z';
             k+=1;
             k-=26;
         }
         s[i]=char(97+k);
          return s;
    }
};