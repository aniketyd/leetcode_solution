class Solution {
public:
    bool dfs(vector<unordered_set<int>>&adj,int node,vector<int>&visited,vector<int>&tempVisited){
       visited[node]=1;
       tempVisited[node]=1;
       for(auto adjnd:adj[node]){
        if(!visited[adjnd]){
            if(dfs(adj,adjnd,visited,tempVisited))return true;
        }
        else if(tempVisited[adjnd])
        return true;
       }
       tempVisited[node]=0;
       return false;
    }
    bool isPrintable(vector<vector<int>>& targetGrid) {
        unordered_map<int,unordered_map<int,int>>rectangle;
        for(int i=1;i<=60;i++)
        rectangle[i][0]=1e9,rectangle[i][2]=1e9;
        int n=targetGrid.size();
        int m=targetGrid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rectangle[targetGrid[i][j]][1]=max(rectangle[targetGrid[i][j]][1],i);
                 rectangle[targetGrid[i][j]][0]=min(rectangle[targetGrid[i][j]][0],i);
                  rectangle[targetGrid[i][j]][2]=min(rectangle[targetGrid[i][j]][2],j);
                   rectangle[targetGrid[i][j]][3]=max(rectangle[targetGrid[i][j]][3],j);
            }
        }
        vector<unordered_set<int>>adj(61);
        for(int k=1;k<=60;k++){
    
          int  minI=rectangle[k][0];
           int  maxI=rectangle[k][1];
           int  minJ=rectangle[k][2];
         int    maxJ=rectangle[k][3];
         
            if(minI==1e9)continue;
            for(int i=minI;i<=maxI;i++){
                for(int j=minJ;j<=maxJ;j++){
                    if(targetGrid[i][j]!=k){
                        adj[k].insert(targetGrid[i][j]);
                    }
                }
            }
        }
        vector<int>visited(61),tempVisited(61);
        
        for(int i=1;i<61;i++){
         
           if(visited[i]==0){
            if(dfs(adj,i,visited,tempVisited))return false;
           }
        }
        return true;
    }
};