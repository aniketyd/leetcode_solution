class Solution {
public:
   int fun(int time, int change, int val){
    int ans=0;
       for(int i=0;i<val-1;i++){
            ans+=time;
            if(((ans+change)/change)%2==0){
                ans=((ans+change)/change)*change;
            }
       }
       ans+=time;
       return ans;
   }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        int m=edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        vector<int>vis(n+1);
        vector<vector<int>>val(n+1,vector<int>(2));
        q.push(1);
        vis[1]=1;
        int c=1;
        while(!q.empty()){
              int s=q.size();
              for(int i=0;i<s;i++){
                  int top=q.front();q.pop();
                  for(auto adjNode:adj[top]){
                    if(vis[adjNode]==0){
                       vis[adjNode]=1;
                       val[adjNode][0]=c;
                       q.push({adjNode});
                    }
                    else if(vis[adjNode]==1&&val[adjNode][0]<c){
                           vis[adjNode]=2;
                           val[adjNode][1]=c;
                           q.push({adjNode});
                    }
                  }
              }
              c++;
        }
        
        return fun(time,change,val[n][1]);
    }
};