class Solution {
public:
    bool isPossible(vector<vector<int>>&p,int mid,int threshold){
    int m=p.size();
    int n=p[0].size();
    for(int i=1;i<=m-mid;i++){
        for(int j=1;j<=n-mid;j++){
            int a=i,b=j,c=mid+i-1,d=mid+j-1;
            int temp=p[c][d]-p[a-1][d]-p[c][b-1]+p[a-1][b-1];
            if(temp<=threshold) return true;
        }
    }
    return false;
}

int maxSideLength(vector<vector<int>>& mat, int threshold) {
     int m=mat.size();
     int n=mat[0].size();
    vector<vector<int>>p(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
          p[i][j]=mat[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        }
    }
     
    int low=1;
    int high=min(m,n);
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(p,mid,threshold)){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
};