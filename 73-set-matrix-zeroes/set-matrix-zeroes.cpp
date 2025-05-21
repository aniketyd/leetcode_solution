class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
       bool f=false,f2=false;
        for(int i=0;i<mt.size();i++){
            
            for(int j=0;j<mt[0].size();j++){
                if(i==0&&mt[i][j]==0)f=true;
                if(j==0&&mt[i][j]==0)f2=true;
                if(mt[i][j]==0){
                   mt[0][j]=0;
                   mt[i][0]=0;
                }
            }
        }
        for(int i=1;i<mt.size();i++){
            if(mt[i][0]==0){
                for(int j=0;j<mt[0].size();j++)
                mt[i][j]=0;
            }
        }
        for(int i=1;i<mt[0].size();i++){
            if(mt[0][i]==0){
                for(int j=0;j<mt.size();j++){
                    mt[j][i]=0;
                }
            }
        }
      if(f) {  for(int i=0;i<mt[0].size();i++)
                mt[0][i]=0;
        }
        if(f2){
            for(int i=0;i<mt.size();i++)
            mt[i][0]=0;
        }

    }
};