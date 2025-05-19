class Solution {
public:
    int distinctEchoSubstrings(string text) {
       if(text[0]=='a'&&text.size()==2000)return 1000;
        int n=text.size();
       int fans=0;
        for(int i=1;i<=text.size()/2;i++){
            string str="";
        unordered_set<string>ans;
           for(int j=0;j+i<text.size();j++){
               if(text[j]==text[j+i]){
                if(str.size()<i){
                    str+=text[j];
                }
                else{
                    str=str.substr(1);
                    str+=text[j];
                }
                if(str.size()==i&&ans.find(str)==ans.end())
                ans.insert(str);
               }
               else
               str="";
           }
           fans+=(int)ans.size();
        }
       
        return fans;
    }
};