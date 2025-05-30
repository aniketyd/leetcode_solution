class Solution {
public:
#define ll long long
vector<vector<ll>>dp;
    void dfs(vector<vector<pair<int,int>>>&adj,int node,int k,int parent){
        ll sum=0;
        vector<ll>diff;
           for(auto &[adjNode,wt]:adj[node]){
            if(adjNode!=parent){
                dfs(adj,adjNode,k,node);
                sum+=dp[adjNode][0];
                diff.push_back(dp[adjNode][1]+wt-dp[adjNode][0]);
            }
           }
           sort(diff.begin(),diff.end(),greater<ll>());
           int c=0;
           while(c<k-1&&(c<diff.size()&&diff[c]>=0)){
            sum+=diff[c];c++;
           }
           dp[node][1]=sum;
           if((c<(diff.size()))&&diff[c]>=0){
         sum+=diff[c];
           }
           dp[node][0]=sum;
           
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n=edges.size();
        vector<vector<pair<int,int>>>adj(n+2);
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        dp.resize(n+2,vector<ll>(2,0));
        dfs(adj,0,k,-2);
     
        return max(dp[0][0],dp[0][1]);

    }
};