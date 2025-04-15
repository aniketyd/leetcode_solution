#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

// order_of_key (k) : Number of items strictly smaller than k
// find_by_order(k) : K-th element in a set (counting from zero).
#define ll long long

class Solution {
public:
    long long goodTriplets(vector<int>& a, vector<int>& b) {
        int n = a.size();
        ordered_set st1,st2;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[b[i]]=i;
        }
        vector<int>sf(n);
        for(int i =n-1;i>=0;i--){
            sf[i] = st1.size() - st1.order_of_key(mp[a[i]]);
            st1.insert(mp[a[i]]);
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            int x = st2.order_of_key(mp[a[i]]);
            ans+=1LL*x*sf[i];
            st2.insert(mp[a[i]]);
        }
        return ans;
    }
};