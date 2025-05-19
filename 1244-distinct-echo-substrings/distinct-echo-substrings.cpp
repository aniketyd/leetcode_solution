class Solution {
public:
    int distinctEchoSubstrings(string text) {
       
        int n=text.size();
       int fans=0;
        for(int i=1;i<=text.size()/2;i++){
            int str=0;
        unordered_set<string>ans;
           for(int j=0;j+i<text.size();j++){
               if(text[j]==text[j+i]){
                if(str<i){
                    str++;
                }
            
                if(str==i)
                ans.insert(text.substr(j-str+1,str));
               }
               else
               str=0;
           }
           fans+=(int)ans.size();
        }
       
        return fans;
    }
};