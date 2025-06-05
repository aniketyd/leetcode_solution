class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        int mod=1e9+7;
        int countSubarray=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                int indx=st.top();
                int nxtIndx=n;
                st.pop();
                if(!st.empty())
                nxtIndx=st.top();
                countSubarray=(countSubarray+1LL*arr[indx]*(indx-i)*(nxtIndx-indx))%mod;
            }
            st.push(i);
        }
        while(!st.empty()){
                int indx=st.top();
                int nxtIndx=n;
                st.pop();
                if(!st.empty())
                nxtIndx=st.top();
                countSubarray=(countSubarray+1LL*arr[indx]*(indx+1)*(nxtIndx-indx))%mod;
            }
    
            return countSubarray;
    }
};