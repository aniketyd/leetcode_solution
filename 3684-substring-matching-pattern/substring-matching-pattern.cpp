class Solution {
public:
    bool fun(string &s,string &p,int i, int j){
         int n=s.size();
        int sz=p.size();
        while(i<n&&j<sz&&s[i]==p[j]){
            ++i;++j;
        }
        return j==sz;
    }
    bool hasMatch(string s, string p) {
        int n=s.size();
        int sz=p.size();
        int j=0;
        string s1="",s2="";
        int f=1;
        for(int i=0;i<sz;i++){
            if(p[i]=='*'){
                f=0;
                continue;
            }
            if(f)s1+=p[i];
            else s2+=p[i];
        }
        for(int i=0;i<n;i++){
            if(fun(s,s1,i,0)||s1.size()==0){
                if(s2.size()==0)return true;
                for(int j=i+s1.size();j<n;j++){
                    if(fun(s,s2,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};