class Solution {
public:
    int check(vector<int>&v,int mid,int n){
        int m=v.size();
        int sum=0;
        for(int i=0;i<m;i++){
            sum+=ceil((v[i]*1.0)/mid);
        }
        if(sum<=n)return 1;
        return 0;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int m=q.size();
        int low=1,high=1e9;
        int ans;
        while(low<=high){
            int mid=(low)+(high-low)/2;
            int res=check(q,mid,n);
            if(res){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};