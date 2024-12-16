class Solution {
public:
    int candy(vector<int>& r) {
      int n=r.size();
      vector<int>req(n);
      vector<pair<int,int>>v;
      for(int i=0;i<n;i++)
      v.push_back({r[i],i});
      sort(v.begin(),v.end());
      for(int i=0;i<n;i++){
        int indx=v[i].second;
        int value=1;
        if(indx-1>=0&&r[indx]>r[indx-1])
        value=max(value,req[indx-1]+1);
        if(indx+1<n&&r[indx]>r[indx+1])
        value=max(value,req[indx+1]+1);
      
        req[indx]=value;
      }
      int sum=0;
      for(int i=0;i<n;i++)
    {  sum+=req[i];}
      return sum;
    }
};