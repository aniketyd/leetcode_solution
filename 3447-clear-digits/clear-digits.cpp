class Solution {
public:
    string clearDigits(string s) {
        
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9'){
                if(st.size()>0)
                    st.pop();
            }
            else
                st.push(s[i]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};