class TreeAncestor {
public:
    vector<vector<int>> dp;
    int nodes;

    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n,vector<int>(16,-1));
        nodes=n;
        for(int i=0;i<n;i++){
            dp[i][0] = parent[i];
        }
        for(int i=1;i<16;i++){
            for(int j=0;j<n;j++){
                if(dp[j][i-1] != -1){
                    dp[j][i]=dp[dp[j][i-1]][i-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int x=0;
        while(k>0 && node != -1){
            if(k % 2 == 1){
                node=dp[node][x];
            }
            x++;
            k = k >> 1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */