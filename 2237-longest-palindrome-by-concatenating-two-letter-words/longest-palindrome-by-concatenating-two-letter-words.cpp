class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int>freq;
        for(int i=0;i<n;i++){
              freq[words[i]]++;
        }
        int flag=0,len=0;
        for(auto &[str,count]:freq){
            if(str[0]==str[1]){
                len+=(count/2)*4;
                if(count%2==1)flag=1;
                continue;
            }
            string cmpStr="";
            cmpStr.push_back(str[1]);
            cmpStr.push_back(str[0]);
            if(freq.find(cmpStr)!=freq.end())
           { len+=min(freq[cmpStr],freq[str])*2;
            }
        }
        if(flag)len+=2;
        return len;
    }
};