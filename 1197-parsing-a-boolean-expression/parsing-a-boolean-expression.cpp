class Solution {
public:
    bool fun(bool f1,bool f2,char ch){
        if(ch=='&')return f1&f2;
        if(ch=='|')return f1|f2;
        return !f1;
    }
    bool parseBoolExpr(string exp) {
        int n=exp.size();
        stack<pair<char,bool>>st;
        st.push({'&',true});
        for(int i=0;i<n;i++){
            bool res=false;
            if(exp[i]=='&')res=true;
            if(exp[i]=='|'||exp[i]=='&'||exp[i]=='!')
            st.push({exp[i],res});
            if(exp[i]==')'){
                auto it=st.top();st.pop();
                bool res=fun(it.second,st.top().second,st.top().first);
                if(res!=st.top().second){
                    auto itt=st.top();st.pop();
                    st.push({itt.first,res});
                }
            }
            if(exp[i]=='f'||exp[i]=='t'){
                bool op=false;
                if(exp[i]=='t')op=true;
                bool res=fun(op,st.top().second,st.top().first);
                if(res!=st.top().second){
                    auto itt=st.top();st.pop();
                    st.push({itt.first,res});
                }
            }

        }
        return st.top().second;
    }
};