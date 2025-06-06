class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int finalAns=0;
        for(char ch='A';ch<='Z';ch++){
            int j=0,cnt=0,ans=0;
            for(int i=0;i<n;i++){
                while((s[i]!=ch&&cnt>=k)){
                    if(s[j]!=ch)cnt--;j++;
                }
                if(s[i]!=ch)cnt++;
                ans=max(ans,i-j+1);
            }
            finalAns=max(finalAns,ans);
        }
        return finalAns;
    }
};