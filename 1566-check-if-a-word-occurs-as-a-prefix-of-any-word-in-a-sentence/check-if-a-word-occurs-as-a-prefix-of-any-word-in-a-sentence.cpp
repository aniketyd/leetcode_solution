class Solution {
public:
    bool fun(string &s,string &sw,int i,int j){
        int n=s.size();
        int m=sw.size();
        while(i<n&&s[i]!=' '&&j<m){
            if(s[i]==sw[j]){i++;j++;}
            else 
            return false;
        }
        if(j==m)return true;
       return false;
    }
    int isPrefixOfWord(string s, string sw) {
        int n=s.size();
        s.push_back(' ');
        int c=1;
        int j=0;
        for(int i=0;i<n;i++){
           if(i==0){
            if(fun(s,sw,i,0))return c;
           }
           if(s[i]==' '){
            c++;
            if(fun(s,sw,i+1,0))
            return c;
           }
        }
        return -1;
    }
};