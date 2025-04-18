class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string res=countAndSay(n-1);
        string ans="";
        int c=1;
        for(int i=1;i<res.size();i++){
            if(res[i]!=res[i-1]){
                string str=to_string(c);
                ans+=str;
                ans+=res[i-1];
                c=1;
            }
            else
            c++;
        }
        string str=to_string(c);
                ans+=str;
                ans+=res[res.size()-1];
               
                return ans;
    }
};