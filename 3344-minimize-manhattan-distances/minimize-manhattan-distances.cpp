class Solution {
public:
    int fun(vector<vector<int>>&pt,int indx,int n){
        int st=1;
        int l1,l2;
         l1=pt[0][0]+pt[0][1];
            l2=pt[0][0]-pt[0][1];
        if(indx==0){
            st=2;
            l1=pt[1][0]+pt[1][1];
            l2=pt[1][0]-pt[1][1];
        }
        if(indx==1){
            st=2;
        }
        int ans=0;
        for(int i=st;i<n;i++){
            if(i==indx)continue;
           int temp=pt[i][0]+pt[i][1]-l1;
           ans=max(ans,temp);
           temp=pt[i][0]-pt[i][1]-l2;
           ans=max(ans,temp);
           l1=min(l1,pt[i][0]+pt[i][1]);
           l2=min(l2,pt[i][0]-pt[i][1]);
        }
        return ans;
    }
    int minimumDistance(vector<vector<int>>& pt) {
         int n=pt.size();
         sort(pt.begin(),pt.end());
         int l1=pt[0][0]+pt[0][1],idx1=0;
         int l2=pt[0][0]-pt[0][1],idx2=0;
         int ans=0;
         int indx1,indx2;
         for(int i=1;i<n;i++){
            int temp=pt[i][0]+pt[i][1]-l1;
            if(temp>ans){
                ans=temp;
                indx1=idx1;
                indx2=i;
            }
            temp=pt[i][0]-pt[i][1]-l2;
            if(temp>ans){
                ans=temp;
                indx1=idx2;
                indx2=i;
            }
            if(pt[i][0]+pt[i][1]<l1){
                l1=pt[i][0]+pt[i][1];
                idx1=i;
            }
            if(pt[i][0]-pt[i][1]<l2){
                l2=pt[i][0]-pt[i][1];
                idx2=i;
            }
         }
        
         ans=min(fun(pt,indx1,n),fun(pt,indx2,n));
         return ans;

    }
};