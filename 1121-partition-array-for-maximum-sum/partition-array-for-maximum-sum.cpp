class Solution {
public:
int K;
    unordered_map<int ,unordered_map<int,int>>dp;
    vector<vector<int>>mx;
    int fun(vector<int>&arr,int i,int j){
        if(i==arr.size())return 0;
        if(dp[i].find(j)!=dp[i].end())return dp[i][j];
        int m=fun(arr,i+1,i+1)+mx[j][i]*(i-j+1);
        if(i-j+1!=K){
            m=max(m,fun(arr,i+1,j));
        }
        return dp[i][j]=m;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        K=k;
        mx.resize(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++){
            int m=arr[i];
            for(int j=i;j<n;j++){
                m=max(m,arr[j]);
                mx[i][j]=m;
            }
        }
        return fun(arr,0,0);
    }
};