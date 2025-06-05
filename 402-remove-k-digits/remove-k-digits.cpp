class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        string ans="";
        for(int i=0;i<n;i++){
           while(!st.empty()&&st.top()>num[i]&&k>0){
            st.pop();k--;
           }
           if(k==0){
               while(!st.empty()){
                ans+=st.top();
                st.pop();
               }
               reverse(ans.begin(),ans.end());
               for(int j=i;j<n;j++)
               ans+=num[j];
               reverse(ans.begin(),ans.end());
               while(ans.size()>1&&ans.back()=='0')
               ans.pop_back();
               reverse(ans.begin(),ans.end());
               return ans;
           }
           st.push(num[i]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
       
        reverse(ans.begin(),ans.end());
         n=ans.size();
        ans=ans.substr(0,n-k);
        reverse(ans.begin(),ans.end());
         while(ans.size()>1&&ans.back()=='0')
               ans.pop_back();
               reverse(ans.begin(),ans.end());
               if(ans.size()==0)return "0";
               return ans;
     
        
    }
};