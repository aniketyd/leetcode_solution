class Solution {
public:
    vector<int>dp;
    vector<int>prime;
    void seivesAlgo(int n){
        prime[0]=prime[1]=0;
        for(int i=2;i<=n;i++){
            if(prime[i]==1){ 
            for(long long j=1LL*i*i;j<=n;j+=i){
                prime[j]=0;
            }
            }
        }
    }
    long long ans=0;
    void dfs2(vector<vector<int>>&adj,int node,int parent){
       
        if(prime[node]==1){
            long long totalPath=0;
            for(auto adjNode:adj[node]){
            totalPath+=dp[adjNode];
        }
        // cout<<ans<<' '<<node<<' '<<totalPath<<endl;
           ans+=totalPath;
           for(auto adjNode:adj[node]){
            totalPath-=dp[adjNode];
            ans+=1LL*totalPath*dp[adjNode];
           }
    //    cout<<ans<<' '<<node<<' '<<totalPath<<endl;
        }
        else{
        long long sumPar=0;
        if(dp[parent]!=0)
        sumPar=dp[parent]-dp[node];
        dp[node]+=sumPar;
        }
        for(auto adjNode:adj[node]){
            if(adjNode!=parent){
                dfs2(adj,adjNode,node);
            }
        }
    }
    void dfs(vector<vector<int>>&adj,int node,int parent){
        int sum=0;
        for(auto adjNode:adj[node]){
            if(adjNode!=parent){
                dfs(adj,adjNode,node);
                sum+=dp[adjNode];
            }
        }
        sum+=1;
        if(prime[node]==1)sum=0;
        dp[node]=sum;

    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        dp.resize(n+1);
        vector<vector<int>>adj(n+10);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        prime.resize(n+4,1);
        seivesAlgo(n+1);
        dfs(adj,1,0);
        // cout<<dp[4]<<endl;
        dfs2(adj,1,0);
        // cout<<dp[4]<<endl;
        return ans;
    }
};