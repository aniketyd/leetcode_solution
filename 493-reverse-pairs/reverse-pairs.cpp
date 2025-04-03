#define ll long
#include <ext/pb_ds/assoc_container.hpp> 
 #include <ext/pb_ds/tree_policy.hpp>//multiset use less_equal<ll>
 using namespace __gnu_pbds; //order_of_key(number),find_by_order(index).(0 based idexing)
 #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        ordered_set st;
        int ans=0;
        for(int i=0;i<n;i++){
          int v=st.order_of_key(1LL*2*nums[i]+1);
          ans+=st.size()-v;
          st.insert(nums[i]);
        }
        return ans;
    }
};