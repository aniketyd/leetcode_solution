class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int m) {
        int n=nums.size();
        vector<int>ans;
        int x=0;
        for(int i=0;i<n;i++){
            x=x^nums[i];
            int k=x,c=0,res=0;
            while(c<m){
                if(k%2==0)
                res+=(1<<c);
                c++;
                k/=2;
            }
            ans.push_back(res);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};