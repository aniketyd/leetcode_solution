class Solution {
public:
    vector<vector<int>>coPrime;
    vector<vector<int>>adj;
    vector<int>ans;
    set<pair<int,pair<int,int>>>st;
  
    void dfs(int node,int parent,vector<int>&nums,int currLevel){
        int ancestorNode=-1,lvl=0;
        for(auto pairVal:coPrime[nums[node]]){
             auto it=st.lower_bound({pairVal,{-1e6,-1}});
             if(it==st.end())continue;
             auto val=(*it);
             if(val.first==pairVal){
                if(abs(val.second.first)>=lvl){
                    ancestorNode=val.second.second;
                    lvl=abs(val.second.first);
                }
             }
        }
        ans[node]=ancestorNode;
       
        st.insert({nums[node],{-1*currLevel,node}});
        for(auto adjNode:adj[node]){
            if(adjNode!=parent){
                dfs(adjNode,node,nums,currLevel+1);
            }
        }
        auto it=st.find({nums[node],{-1*currLevel,node}});
        if(it!=st.end())
        st.erase(it);

    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        coPrime.resize(51);
        adj.resize(n+1);
        for(int i=0;i<edges.size();i++){
             adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=1;i<51;i++){
              for(int j=1;j<51;j++){
                if(__gcd(i,j)==1){
                    coPrime[i].push_back(j);
                }
              }
        }
        ans.resize(n);
        dfs(0,-1,nums,0);
        return ans;

        
    }
};