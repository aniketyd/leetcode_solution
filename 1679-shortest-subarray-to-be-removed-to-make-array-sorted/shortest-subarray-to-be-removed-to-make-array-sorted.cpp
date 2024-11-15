class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        
        int indx1=0,indx2=n-1;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1])
            indx1++;
            else break;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1])
            indx2--;
            else 
            break;
        }
        if(indx1>=indx2)return 0;
        int ans=max(indx1+1,n-indx2);
        for(int i=0;i<=indx1;i++){
        int it=lower_bound(arr.begin()+indx2,arr.end(),arr[i])-arr.end();
        
            ans=max(ans,-1*it+i+1);
        }
        return n-ans;

    }
};