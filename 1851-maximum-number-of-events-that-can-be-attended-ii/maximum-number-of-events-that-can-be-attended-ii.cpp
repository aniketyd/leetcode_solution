class Solution {
public:
    vector<int>temp;
    vector<vector<int>>dp;
  
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end(),cmp);
        for(int i=0;i<n;i++){
            temp.push_back(events[i][1]);
        }
        dp.resize(n+1,vector<int>(k+1,0));
       
        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){
                int take=events[i][2];
            auto indx=lower_bound(temp.begin(),temp.end(),events[i][0])-temp.begin();
            if(indx!=0)
            take+=dp[indx-1][j-1];
            int not_take=0;
            if(i!=0)
         not_take=dp[i-1][j];
            
            dp[i][j]=max(take,not_take);
            
            }
        }
        return dp[n-1][k];

    }
};