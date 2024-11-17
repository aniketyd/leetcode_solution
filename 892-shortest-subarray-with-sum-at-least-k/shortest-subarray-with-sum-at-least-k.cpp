class Solution {
public:
    int shortestSubarray(vector<int>&v, int k) {
        set<pair<long long,long long>>st;
        int n=v.size();
        long long pf=0;int ans=1e7;
        vector<long long>fp(n+1);
        st.insert({0LL,0LL});
        for(int i=0;i<n;i++)
        fp[i+1]+=v[i]+fp[i];
        for(int i=0;i<n;i++){
            pf+=v[i];
             while(st.size()>0){
                auto it=st.end();
                --it;
                if((*it).first>=(pf)){
                    st.erase(it);
                }
                else{
                    break;
                }
            }
            st.insert({pf,i+1});
            auto it=st.lower_bound({pf-k+1,-1LL});
            if((*it).second==0&&pf>=k||(((*it).second!=0)&&pf-fp[((*it).second)-1]>=k)){
                int k=i+2-((*it).second);
                if((*it).second==0)k--;
            ans=min(ans,k);
            cout<<i<<' '<<((*it).second)<<endl;
            }
            else if(it!=st.begin()){
                --it;
                 if((*it).second==0&&pf>=k||(((*it).second!=0)&&pf-fp[((*it).second)]>=k)){
                int k=i+2-((*it).second)-1;
               
            ans=min(ans,k);
            cout<<i<<' '<<((*it).second)<<endl;
            }
            }
           
        }
        if(ans==1e7)return -1;
        return ans;
    }
};