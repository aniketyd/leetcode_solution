class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,int &cnt,unordered_set<int>&check,vector<int>&vis){
        vis[node]=1;
       
        if(check.find(node)!=check.end())cnt++;
        for(auto nextNode:adj[node]){
            if(vis[nextNode]==0)
            dfs(nextNode,adj,cnt,check,vis);
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>adj(1e5+1);
        unordered_set<int>check;
        for(int i=0;i<n;i++){
            check.insert(nums[i]);
            for(int j=2;j*j<=nums[i];j++){
               if(nums[i]%j==0) {
                
                    int q=nums[i]/j;
                    
                    adj[j].push_back(nums[i]);
                    adj[nums[i]].push_back(j);
                    adj[q].push_back(nums[i]);
                    adj[nums[i]].push_back(q);
                }
            }
        }
        vector<int>vis(1e5+1);
        int ans=0;
        for(int i=1;i<=1e5;i++){
            if(vis[i]==0){
                int cnt=0;
                dfs(i,adj,cnt,check,vis);
                 ans=max(ans,cnt);
            }
            
        }
        return ans;
    }
};