class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& it, vector<int>& q) {
        sort(it.begin(),it.end());
        int n=it.size();
        vector<int>v(n),ans;
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,it[i][1]);
            v[i]=mx;
        }
       
        for(int i=0;i<q.size();i++){
             vector<int>vv={q[i]+1,0};
           int indx = upper_bound(it.begin(), it.end(),vv ) - it.begin();

             if(indx==0)
             ans.push_back(0);
             else
        {     indx--;
             ans.push_back(v[indx]);}
        }
        return ans;
    }
};