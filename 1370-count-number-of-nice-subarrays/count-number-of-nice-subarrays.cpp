class Solution {
public:
        int numberOfSubarrays(vector<int>& A, int k) {
            // cout<<atMost(A,k)<<endl;
            // cout<<atMost(A,k+1)<<endl;
        return atMost(A, k) - atMost(A, k+1 );
    }

    int atMost(vector<int>& A, int k) {
        int res = 0, i = 0, n = A.size(),cnt=0;
        for (int j = 0; j < n; j++) {
            while(i<n&&cnt<k){
                if(A[i]%2!=0)cnt++;
                i++;
            }
            if(cnt==k)
            res+=(n-i+1);
            if(A[j]%2!=0)cnt--;
        }
        return res;
    }
};