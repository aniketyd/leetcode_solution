class Solution {
public:
    vector<int>temp;
    vector<vector<int>>dp;
    int fun(vector<vector<int>>&events,int k,int n){
            if(n<0||k==0)return 0;
            if(dp[n][k]!=-1)return dp[n][k];
            int take=events[n][2];
            auto indx=lower_bound(temp.begin(),temp.end(),events[n][0])-temp.begin();
            if(indx!=0)
            take+=fun(events,k-1,indx-1);
            int not_take=fun(events,k,n-1);
            dp[n][k]=max(take,not_take);
            return dp[n][k];

    }
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end(),cmp);
        for(int i=0;i<n;i++){
            temp.push_back(events[i][1]);
        }
        dp.resize(n+1,vector<int>(k+1,-1));
        return fun(events,k,n-1);

    }
};