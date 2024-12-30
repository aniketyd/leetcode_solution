class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.size();
        int j=-1;
        for(int i=n-1;i>=0;i--)
        if(s[i]=='1'){
            j=i;
            break;
        }
        if(j==-1)return 0;
        int prev=0;int c=0,wt=0;
        for(int i=j;i>=0;i--){
           if(s[i]=='1'){
            c++;
            if(i<n-1&&s[i]==s[i+1]&&wt>0)
            wt--;
           }
           else{
            
            if(s[i]==s[i+1])
            wt++;
            prev=wt+c;
           }
        }
        return prev;
    }
};
//000011
//
//010101
//101010
//110100
//111000