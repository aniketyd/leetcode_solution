class Solution {
public:
    void dfs(int node,int parent,int depth,vector<pair<int,int>> &gg,vector<int> &ans,vector<vector<int>> &coprime,vector<int> &nums,vector<vector<int>> &adj){
        int dep=-1;
        int ances=-1;
        for(int i=1;i<51;i++){
            if(coprime[nums[node]][i])
            {
                auto it=gg[i];
                if(it.second>dep){
                    dep=it.second;
                    ances=it.first;
                }
            }
        }
        ans[node]=ances;
        pair<int, int> prev = gg[nums[node]];
        gg[nums[node]] = {node, depth};
        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node, depth + 1,gg,ans,coprime,nums,adj);
            }
        }
        gg[nums[node]] = prev;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> coprime(51,vector<int>(51,-1));
        for(int i=1;i<51;i++){
            for(int j=1;j<51;j++){
                coprime[i][j]=(__gcd(i,j)==1);
            }
        }
        int n=nums.size();
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<pair<int,int>> gg(51,{-1,-1});
        vector<int> ans(n,-1);
        dfs(0,-1,0,gg,ans,coprime,nums,adj);
        return ans;
    }
};