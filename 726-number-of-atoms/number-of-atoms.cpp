class Solution {
public:
    string countOfAtoms(string formula) {
       
      map<string,int>mp;
      reverse(formula.begin(),formula.end());
      int n=formula.size();
      stack<int>st;
      int curr=1,prev=1;
      for(int i=0;i<n;i++){
        if((formula[i]>='a'&&formula[i]<='z')||(formula[i]>='A'&&formula[i]<='Z')){
               string temp="";
               while(i<n&&formula[i]<='z'&&formula[i]>='a')
              {    temp+=formula[i];
                   i++;
              }
              temp+=formula[i];
              reverse(temp.begin(),temp.end());
              mp[temp]+=curr*prev;
              prev=1;
        }
        if(formula[i]==')'){
            st.push(prev);
            curr*=prev;
            prev=1;
        }
        if(formula[i]=='('){
          curr/=st.top();
          st.pop();
        }
        if(formula[i]<='9'&&formula[i]>='0'){
            string temp="";
              while(i<n&&formula[i]<='9'&&formula[i]>='0'){
                   temp+=formula[i];
                   i++;
              }
              reverse(temp.begin(),temp.end());
              int val=stoi(temp);
              prev=val;
              i--;
        }
      }
   
      string ans="";
       for(auto &[str,val]:mp){
        ans+=str;
        if(val!=1)
        ans+=to_string(val);
       }
      return ans;
    }
};