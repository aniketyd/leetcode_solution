class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, h=n-1,ans=0;
        while(l<h){
            ans=max(ans,min(height[l],height[h])*(h-l));
            if(height[l]>height[h])h--;
            else l++;
        }
        return ans;
    }
};