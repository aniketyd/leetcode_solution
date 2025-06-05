class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        long long negSum=0,posSum=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>nums[i]){
                 int indx=st.top();
                 st.pop();
                 int nxtIndx=n;
                 if(!st.empty())
                 nxtIndx=st.top();
                 negSum=(negSum+1LL*nums[indx]*(indx-i)*(nxtIndx-indx));   
            }
            st.push(i);
        }
        while(!st.empty()){
                 int indx=st.top();
                 st.pop();
                 int nxtIndx=n;
                 if(!st.empty())
                 nxtIndx=st.top();
                 negSum=(negSum+1LL*nums[indx]*(indx+1)*(nxtIndx-indx));   
            }


            for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                 int indx=st.top();
                 st.pop();
                 int nxtIndx=n;
                 if(!st.empty())
                 nxtIndx=st.top();
                 posSum=(posSum+1LL*nums[indx]*(indx-i)*(nxtIndx-indx));   
            }
            st.push(i);
        }
        while(!st.empty()){
                 int indx=st.top();
                 st.pop();
                 int nxtIndx=n;
                 if(!st.empty())
                 nxtIndx=st.top();
                 posSum=(posSum+1LL*nums[indx]*(indx+1)*(nxtIndx-indx));   
            }
           
           long long ans=1LL*posSum;
           ans-=negSum;
            return ans;

    }
};