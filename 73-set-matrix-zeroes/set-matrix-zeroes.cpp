class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
        unordered_map<int,int>mpx,mpy;
        for(int i=0;i<mt.size();i++){
            for(int j=0;j<mt[0].size();j++){
                if(mt[i][j]==0){
                    mpx[i]=1;
                    mpy[j]=1;
                }
            }
        }
        for(auto &x:mpx){
           for(int j=0;j<mt[0].size();j++)
           mt[x.first][j]=0;
        }
        for(auto &y:mpy){
           for(int i=0;i<mt.size();i++)
           mt[i][y.first]=0;
        }
    }
};