class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>>adj(n);
        vector<int>degree(n),vis(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][1]]++;
            degree[edges[i][0]]++;
        }
        queue<int>leaf;
        for(int i=0;i<n;i++){
            if(degree[i]==1&&coins[i]==0)
             leaf.push(i);
        }
        int ans=n;
        while(!leaf.empty()){
            int currNode=leaf.front();
            vis[currNode]=1;
            leaf.pop();
            ans--;
            degree[currNode]=0;
            for(auto adjNode:adj[currNode]){
                if(degree[adjNode]==0)continue;
                degree[adjNode]--;
                if(vis[adjNode]==0&&degree[adjNode]==1&&coins[adjNode]==0){
                    leaf.push(adjNode);
                    degree[adjNode]=0;
                    vis[adjNode]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(degree[i]==1&&vis[i]==0){
                ans--;vis[i]=1;
                for(auto adjNode:adj[i]){
                    if(degree[adjNode]==0)continue;
                    degree[adjNode]--;
                    if(degree[adjNode]<=1&&vis[adjNode]==0){
                        ans--; vis[adjNode]=1;
                    }
                }
            }
        }
        return max((ans-1)*2,0);

    }
};