class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n=nums.size();
        if(n<3)return false;
        multiset<int>st;
        for(int i=2;i<n;i++)st.insert(nums[i]);
        int mi=nums[0];
        for(int i=1;i<n-1;i++){
            if(mi<nums[i]){
                auto it=st.upper_bound(mi);
               
                if(it!=st.end()){
                    
                    if((*it)<nums[i]){
                        return true;
                    }
                }
                  
            }
            mi=min(mi,nums[i]);
            auto itt=st.find(nums[i+1]);
            st.erase(itt);
        }
        return false;
    }
};