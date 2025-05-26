class Solution {
     vector<vector<int>> dp; 
public: 
    
    bool dfs(vector<vector<int>> &g,int src,int dest,vector<int> &numberVisit,int prev=-1){
        if(src==dest){ 
            numberVisit[dest]++;
            return true;
        } 
        
        for(auto x:g[src]){
            if(x!=prev&&dfs(g,x,dest,numberVisit,src)){
                numberVisit[src]++;  
                return true;
            }
        } 
        
        return false;
    } 
    
    

    
    void solve(vector<vector<int>> &g,int src,int prev,vector<int>& price){
        int node=src;
       dp[src][0]=price[src];
       dp[src][1]=price[src]/2;
       for(auto adjNode:g[src]){
        if(adjNode!=prev){
            solve(g,adjNode,src,price);
        }
       }
       int take=0,not_take=0;
       for(auto adjNode:g[src]){
        if(adjNode==prev)continue;
          take+=dp[adjNode][0];
          not_take+=min(dp[adjNode][0],dp[adjNode][1]);
       }
       dp[node][0]+=not_take;
       dp[node][1]+=take;
    }
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) { 
        
        vector<vector<int>> g(n); 
	    vector<int> numberVisit(n);  
		
        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        } 
 
        for(auto x:trips)
            dfs(g,x[0],x[1],numberVisit);
        
        int withouthalf=0;
        
        for(int i=0;i<n;i++)
            price[i]=price[i]*numberVisit[i]; 
        
        
        for(int i=0;i<n;i++){
            withouthalf+=price[i]; 
        } 
        
        dp.resize(n,vector<int>(2));
        
         solve(g,0,-1,price);
     
        return min(dp[0][0],dp[0][1]);
    }
};