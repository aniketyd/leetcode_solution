class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int indx=st.top();
                int prevIndx=-1;
                st.pop();
                if(!st.empty())
                prevIndx=st.top();
                ans=max(ans,heights[indx]*(i-prevIndx-1));
            }
            st.push(i);
        }
        while(!st.empty()){
                int indx=st.top();
                int prevIndx=-1;
                st.pop();
                if(!st.empty())
                prevIndx=st.top();
                ans=max(ans,heights[indx]*(n-prevIndx-1));
            }
            return ans;
    }
};