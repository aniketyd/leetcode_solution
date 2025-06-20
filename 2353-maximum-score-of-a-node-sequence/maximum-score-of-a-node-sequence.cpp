class Solution {
public:
    int maximumScore(vector<int>& score, vector<vector<int>>& edges) {
        int n=score.size();
        int m=edges.size();
      
        vector<vector<int>>mx(n,vector<int>(3,-1));
        for(int i=0;i<m;i++){
           int a=edges[i][0],b=edges[i][1];
           if(mx[a][0]==-1||score[mx[a][0]]<score[b]){
            mx[a][2]=mx[a][1];
            mx[a][1]=mx[a][0];
            mx[a][0]=b;
           }
           else if(mx[a][1]==-1||score[mx[a][1]]<score[b])
          { mx[a][2]=mx[a][1];
           mx[a][1]=b;}
           else if(mx[a][2]==-1||score[mx[a][2]]<score[b])
           mx[a][2]=b;

            if(mx[b][0]==-1||score[mx[b][0]]<score[a]){
            mx[b][2]=mx[b][1];
            mx[b][1]=mx[b][0];
            mx[b][0]=a;
           }
           else if(mx[b][1]==-1||score[mx[b][1]]<score[a])
          { mx[b][2]=mx[b][1];
           mx[b][1]=a;}
           else if(mx[b][2]==-1||score[mx[b][2]]<score[a])
           mx[b][2]=a;
           
        }
        int ans=-1;
        for(int i=0;i<m;i++){
             int a=edges[i][0],b=edges[i][1];
             vector<int>v1,v2;
             for(int j=0;j<3&&v1.size()<2;j++){
                if(mx[a][j]==b||mx[a][j]==-1)continue;
                 v1.push_back(mx[a][j]);
             }
              for(int j=0;j<3&&v2.size()<2;j++){
                if(mx[b][j]==a||mx[b][j]==-1)continue;
                 v2.push_back(mx[b][j]);
             }
             for(int j=0;j<v1.size();j++){
                for(int k=0;k<v2.size();k++){
                    if(v1[j]!=v2[k])
                    ans=max(ans,score[a]+score[b]+score[v1[j]]+score[v2[k]]);
                }
             }
        }
        return ans;
    }
};