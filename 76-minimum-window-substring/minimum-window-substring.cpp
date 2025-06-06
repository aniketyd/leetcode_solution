class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int>curfreq(301),freq(301);
        for(int i=0;i<m;i++){
            freq[t[i]-'A']++;
        }
        int reqChar=0;
        for(int i=0;i<200;i++)
        if(freq[i]>0)reqChar++;
        int sz=1e9;
        int start,end;
        int j=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            while(j<n&&cnt<reqChar){
                curfreq[s[j]-'A']++;
                if(freq[s[j]-'A']==curfreq[s[j]-'A'])cnt++;
                j++;
            }
            if(cnt==reqChar){
               if((j-i)<sz){
                sz=j-i;
                start=i;
                end=j;
               }
            }
            if(curfreq[s[i]-'A']==freq[s[i]-'A'])
            cnt--;
            curfreq[s[i]-'A']--;
        }
        if(sz==1e9)return "";
        return s.substr(start,end-start);
    }
};