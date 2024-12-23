class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int pf=0,sum=0,c=0;
        for(int i=0;i<n;i++){
            pf+=arr[i];
            sum+=i;
            if(pf==sum)
            c++;
        }
        return c;
    }
};