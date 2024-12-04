class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        int i=0,j=0;
       for(int i=0;i<n2;i++){
           while(j<n1&&!(str2[i]-str1[j]==1||str2[i]==str1[j]||(str2[i]=='a'&&str1[j]=='z'))){
            j++;
           }
           if(j==n1)return false;
          
          j++;
       }
       return true;
    }
};