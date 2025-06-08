class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                int indx=st.top();
                st.pop();
                int prevIndx=-1;
                if(!st.empty())
                prevIndx=st.top();
                if(nums[indx]>(threshold/(i-prevIndx-1)))
                return (i-prevIndx-1);
            }
            st.push(i);
         
        }
         while(!st.empty()){
            int i=n;
                int indx=st.top();
                st.pop();
                int prevIndx=-1;
                if(!st.empty())
                prevIndx=st.top();
                if(nums[indx]>(threshold/(i-prevIndx-1)))
                return (i-prevIndx-1);
            }
            return -1;
    }
};