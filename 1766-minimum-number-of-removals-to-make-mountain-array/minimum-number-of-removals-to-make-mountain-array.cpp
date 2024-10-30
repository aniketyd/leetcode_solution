class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        int lisu[n],lisd[n];
        for(int i=0;i<n;i++)
         {
             lisu[i]=1;
             for(int j=0;j<i;j++)
             {
                 if(arr[i]>arr[j])
                 lisu[i]=max(lisu[i],lisu[j]+1);
             }
         }
          for(int i=n-1;i>=0;i--)
         {
             lisd[i]=1;
             for(int j=n-1;j>i;j--)
             {
                 if(arr[i]>arr[j])
                 lisd[i]=max(lisd[i],lisd[j]+1);
             }
         }
         int res=-1;
         for(int i=0;i<n;i++)
         {
             if(lisu[i]!=1&&lisd[i]!=1)
             res=max(res,lisu[i]+lisd[i]-1);
         }
         return (n-res);

    }
};