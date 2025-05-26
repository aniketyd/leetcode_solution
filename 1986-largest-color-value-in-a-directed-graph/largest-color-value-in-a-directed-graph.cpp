class Solution {
public:
    vector<vector<int>>freq;
    string Colors;
    int n;
    void addFreq(vector<int>&f1, vector<int>&f2){
        for(int i = 0; i < 26; i++){
            f1[i] += f2[i]; 
        }
        return;
    }
    void dfs(int i, vector<int>&vis, vector<vector<int>>& adj){
        vis[i] = 1;
        vector<int>curFreq(26);
        for(auto &x: adj[i]){
            if(!vis[x]){
                dfs(x, vis, adj);
            }
            for(int j = 0; j < 26; j++){
                curFreq[j] = max(curFreq[j], freq[x][j]);
            }
        }
        addFreq(freq[i], curFreq);
    }
    bool isDAG(int i, vector<int>& vis, vector<vector<int>>& adj) {
        if(vis[i] == 1)return false;
        if(vis[i] == 2)return true;
        vis[i] = 1;
        for(auto &x : adj[i]) {
            if(!isDAG(x, vis, adj))return false;
        }
        vis[i] = 2;
        return true;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        Colors = colors;
        vector<vector<int>> adj(n);
        freq = vector<vector<int>>(n, vector<int>(26, 0));
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
        }
        vector<int>vis(n);
        for(int i = 0; i < n; i++){
            freq[i][Colors[i]-'a'] = 1;
            if(!vis[i]){
                if(!isDAG(i, vis, adj))return -1;
            }
        }
        vis = vector<int>(n, 0);
        int ans  = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
        for(auto &i: freq){
           ans = max(ans, *max_element(i.begin(), i.end()));
        }
        return ans;
    }
};