class Solution {
public:
    bool fun(vector<int>& t, vector<int>& w, int p, int s, int mid) {
        if (mid == 0) return true;

        multiset<int> st;
        int n = w.size();
        // Add the strongest `mid` workers to the multiset
        for (int i = n - mid; i < n; ++i) {
            st.insert(w[i]);
        }

        int c = 0;

        // Assign the hardest `mid` tasks (from end)
        for (int i = mid - 1; i >= 0; --i) {
            auto itt=st.end();
        --itt;
          auto val=*(itt);
          if(t[i]>val){
            c++;
            if(t[i]>val+s)return false;
            auto it=st.lower_bound(t[i]-s);
            if(it==st.end())return false;
            st.erase(it);
          }
          else if(st.size()>0){
            auto it=st.end();
            --it;
            st.erase(it);
          }
        }
        if(c>p)return false;
        return true;
    }

    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int s) {
        sort(t.begin(), t.end());
        sort(w.begin(), w.end());

        int low = 0, high = min((int)t.size(), (int)w.size());
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (fun(t, w, p, s, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
