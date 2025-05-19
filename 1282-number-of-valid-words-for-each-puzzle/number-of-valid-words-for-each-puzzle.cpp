class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n=words.size();
        int m=words[0].size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
           int val=0;
           for(int j=0;j<words[i].size();j++){
            if((val&((1<<(words[i][j]-'a'))))==0)
            val+=(1<<(words[i][j]-'a'));
           
           }
           mp[val]++;
        }
        vector<int>ans(puzzles.size());
        for(int i=0;i<puzzles.size();i++){
            int val=(1<<(puzzles[i][0]-'a'));
            for(int k=0;k<(1<<(puzzles[i].size()-1));k++){
                int c=1;int val2=0,temp=k;
                while(c<puzzles[i].size()&&temp>0){
                    if(temp%2==1)
                    val2+=(1<<(puzzles[i][c]-'a'));
                    c++;
                    temp/=2;
                }
                if(mp.find(val+val2)!=mp.end())
                ans[i]+=mp[val+val2];
            }
        }
        return ans;
    }
};