class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<tuple<int,int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back(make_tuple(endTime[i],startTime[i],profit[i]));
        }
        sort(arr.begin(),arr.end());
        vector<int>dp(n+1);
        for(int i=0;i<n;i++){
            int r=get<0>(arr[i]);
            int l=get<1>(arr[i]);
            int profit=get<2>(arr[i]);
            auto indx=lower_bound(arr.begin(),arr.end(),make_tuple(l+1,0,0))-arr.begin();
            int prevProfits=0;
            if(indx!=0)
            prevProfits=dp[indx-1];
            if(i==0)
            dp[i]=profit;
            else
                dp[i]=max(profit+prevProfits,dp[i-1]); 
        }
        return dp[n-1];
    }
};