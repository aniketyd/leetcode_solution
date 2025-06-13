class DSU{
    public:
    vector<long long>parent,size;
    DSU(int n,vector<int>&v){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i=0;i<n;i++)
        size[i]=v[i];
    }
   int findUlp(int node){
       if(node==parent[node])return node;
       return parent[node]=findUlp(parent[node]);
    }
    void unions(int u, int v){
        int fu=findUlp(u);
        int fv=findUlp(v);
        if(fu==fv)return;
        size[fu]+=size[fv];
        parent[fv]=fu;
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& rQ) {
        int n=nums.size();
        DSU ds(n,nums);
        long long mx=0;
        vector<long long>arr(n),ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=mx;
            int indx=rQ[i];
            if(indx-1>=0&&arr[indx-1]!=0&&indx+1<n&&arr[indx+1]!=0){
                ds.unions(indx-1,indx+1);
                ds.unions(indx-1,indx);
            }
            else if(indx-1>=0&&arr[indx-1]!=0){
                ds.unions(indx-1,indx);
            }
            else if(indx+1<n&&arr[indx+1]!=0){
                ds.unions(indx+1,indx);
            }
            arr[indx]=1;
            mx=max(mx,ds.size[ds.findUlp(indx)]);
        }
        return ans;

    }
};