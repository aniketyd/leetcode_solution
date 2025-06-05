class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1,leftMax=v[0],rightMax=0;
        int ans=0;
        while(r>=l){
            leftMax=max(leftMax,v[l]);
          while(r>=l&&rightMax<leftMax){
            rightMax=max(rightMax,v[r]);
            ans+=rightMax-v[r];
            r--;
          }
          ans+=leftMax-v[l];
          l++;
        }
        return ans;
    }
};