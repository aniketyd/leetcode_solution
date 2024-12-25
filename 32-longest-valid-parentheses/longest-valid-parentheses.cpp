class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int>dp(n+1);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(st.size()>0){
               int indx = st.top();
               st.pop();
               dp[i+1]=dp[indx]+i-indx+1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
        return ans;
    }
};