class Solution {
public:
  int ans=0;
    void dfs(int node, vector<int>&fav,int c,vector<int>&vis){
          vis[node]=c;
          if(vis[fav[node]]!=0&&vis[fav[node]]!=-1){
    
            ans=max(ans,c-vis[fav[node]]+1);
          }
          if(vis[fav[node]]==0)
          dfs(fav[node],fav,c+1,vis);
          vis[node]=-1;
    }
    int dfs2(int node,vector<vector<int>>&adj,vector<int>&vis,int c){
        vis[node]=1;
        int a=0;
        for(auto val:adj[node]){
            if(vis[val]==0&&val!=c)
            a=max(a,dfs2(val,adj,vis,c));
        }
        a++;
        return a;
    }
    int maximumInvitations(vector<int>& fav) {
        int n=fav.size();
        
        vector<int>vis(n),vis2(n),indegree(n);
        vector<vector<int>>rev(n);
        for(int i=0;i<n;i++){
            rev[fav[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            if(i==fav[fav[i]]&&vis2[i]==0){
               ans+=dfs2(i,rev,vis2,fav[i])+dfs2(fav[i],rev,vis2,i);
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++)
        indegree[fav[i]]++;
        for(int i=0;i<n;i++){
         if(indegree[i]==0){
            dfs(i,fav,1,vis);
         }
        }
          for(int i=0;i<n;i++){
           if(vis[i]!=-1)
            dfs(i,fav,1,vis);
         
        }
        return ans;
    }
};