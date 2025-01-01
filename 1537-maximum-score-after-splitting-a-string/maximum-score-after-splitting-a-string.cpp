class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int c=0,cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')
            c++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]=='0')
            cnt++;
            else
            c--;
            ans=max(ans,cnt+c);
        }
        return ans;
    }
};