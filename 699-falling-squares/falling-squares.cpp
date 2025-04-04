class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& p) {
        int n=p.size();
        multiset<tuple<int,int,int>>st;
        st.insert(make_tuple(1,1e9,0));
        vector<int>ans;int ansmx=0;
        for(int i=0;i<n;i++){
            int l=p[i][0];
            int r=l+p[i][1]-1;
            auto it=st.upper_bound(make_tuple(l,1000000004,0));
              auto it2=st.upper_bound(make_tuple(r,1000000004,0));
              vector<tuple<int,int,int>>v;int mx=0;
              for(auto itt=it;itt!=it2;++itt){
                 mx=max(mx,get<2>(*itt));
                 v.push_back(*itt);
              }
             
              --it;--it2;
              v.push_back((*it));
              
              if(get<0>(*it)!=l)
              st.insert(make_tuple(get<0>(*it),l-1,get<2>(*it)));
              if(get<1>(*it2)!=r){
                st.insert(make_tuple(r+1,get<1>(*it2),get<2>(*it2)));
              }
              mx=max(mx,get<2>(*it));
              mx=max(mx,get<2>(*it2));
              mx+=p[i][1];
              ansmx=max(ansmx,mx);
           
           while(!v.empty()){
            if(st.find(v[v.size()-1])!=st.end())
            st.erase(st.find(v[v.size()-1]));
            v.pop_back();
           }
           st.insert(make_tuple(l,r,mx));
           ans.push_back(ansmx);

        }
        // for(auto it:st){
        //    cout<<get<0>(it)<<' '<<get<1>(it)<<' '<<get<2>(it)<<endl;
        // }
        return ans;
    }
};