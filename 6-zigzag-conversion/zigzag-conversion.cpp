class Solution {
public:
   
    string convert(string s, int r) {
        int n=s.size();
        vector<string>v(r);
        if(r==1)return s;
        string ans="";
        int a=0;
        int f=0;
        for(int i=0;i<n;i++){
           v[a].push_back(s[i]);
           if(f==0){
            a++;
           }
           else{
            a--;
           }
           if(a==r){
            f=1;a-=2;
           }
           if(a==-1){
            f=0; a+=2;
           }
        }
        for(int i=0;i<r;i++){
            ans+=v[i];
        }
        return ans;
    }
};