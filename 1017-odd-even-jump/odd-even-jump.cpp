class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        set<pair<int,int>>st;
        vector<vector<int>>dp(n,vector<int>(2));
        dp[n-1][0]=1;
        dp[n-1][1]=1;
        int count=1;
        st.insert({arr[n-1],n-1});
        for(int i=n-2;i>=0;i--){
              auto it=st.lower_bound({arr[i],-1});
              if(it!=st.end()){
                int indx=(*it).second;
                dp[i][0]=dp[indx][1];
              }
              if(it!=st.end()&&(*it).first==arr[i]){
                int indx=(*it).second;
                dp[i][1]=dp[indx][0];
              }
              else if(it!=st.begin()){
                    --it;
                    int val=(*it).first;
                    auto itt=st.lower_bound({val,-1});
                    if(itt!=st.end()){
                        int indx=(*itt).second;
                        dp[i][1]=dp[indx][0];
                    }
              }
              if(dp[i][0])count++;
              st.insert({arr[i],i});
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
        // }
        return count;
    }
};