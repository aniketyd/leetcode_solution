class Solution {
public:
    int minimumCoins(vector<int>& p) {
        int n=p.size();
        deque<int>q;
        vector<int>dp(n+1);
        dp[n]=0;
        q.push_back(n+1);
        for(int i=n;i>=1;i--){
            
            while(!q.empty()&&q.front()>2*i+1){
                q.pop_front();
            }
            dp[i-1]=p[i-1]+dp[q.front()-1];
            while(dp[q.back()-1]>=dp[i-1]){
                q.pop_back();
            }
            q.push_back(i);
        }
      
        return dp[0];
    }
};