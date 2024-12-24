class Solution {
public:
int x;





pair<int,int> diameter(vector<vector<int>>& adj, int n,int parent)
{
   int mx1=0,mx2=0;
   int ans=0;
   for(auto node:adj[n]){
      if(node!=parent){
         auto val=diameter(adj,node,n);
         ans=max(ans,val.first);
         if(val.second>=mx1){
            mx2=mx1;
            mx1=val.second;
         }
         else if(val.second>mx2){
            mx2=val.second;
         }
      }
   }
   ans=max(ans,mx1+mx2);
   
      return {ans,mx1+1};
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;int m=edges2.size()+1;
        vector<vector<int>>adj1(n),adj2(m);
        for(int i=0;i<n-1;i++)
        {
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }
          for(int i=0;i<m-1;i++)
        {
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }
        if(n==0&&m==0)return 1;
      
        auto d11=diameter(adj1,0,-1);
        auto d22=diameter(adj2,0,-1);
         int d1=max(d11.first,d11.second-1);
         int d2=max(d22.first,d22.second-1);
         
        int c1=(d1+1)/2;
        int c2=(d2+1)/2;
        int ans;
        ans=max(c1+c2+1,d1);
        ans=max(ans,d2);
        return ans;
    }
};