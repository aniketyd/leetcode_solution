class TreeAncestor {
public:
vector<vector<int>>adj;
unordered_map<int,unordered_map<int,int>>dp;
    void dfs(int node,int parent){
   
        dp[node][0]=parent;
       for(int i=1;i<20;i++){
        dp[node][i]=dp[dp[node][i-1]][i-1];
       }
       
       for(auto adjnd:adj[node]){
        if(adjnd!=parent){
            dfs(adjnd,node);
        }
       }
    }
    TreeAncestor(int n, vector<int>& parent) {
        adj.resize(n+1);
        
        for(int i=1;i<n;i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        for(int i=0;i<20;i++)
        dp[-1][i]=-1;
        dfs(0,-1);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++){
            if(k&(1<<i)){
                node=dp[node][i];
          
            }
        }
       

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */