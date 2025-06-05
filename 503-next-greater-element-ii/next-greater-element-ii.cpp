class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
     int n=nums.size();
     stack<int>monoStack;
     vector<int>nextGreaterEle(n,-1);
     for(int i=2*n-1;i>=0;i--){
        int j=i%n;
          while(monoStack.size()>0&&monoStack.top()<=nums[j]){
            monoStack.pop();
          }
        if(i<n&&!monoStack.empty())
        nextGreaterEle[i]=monoStack.top();
        monoStack.push(nums[j]);
     }   
     return nextGreaterEle;
    }
};