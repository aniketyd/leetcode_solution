class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        stack<int>st;
        int curr=1,prev=1;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(s[i]>='0'&&s[i]<='9'){
                long long num=0;
                while(i<n&&s[i]>='0'&&s[i]<='9'){
                    num=num*10+s[i]-'0';
                    i++;
                }
                sum+=curr*prev*num;
               
            }
            if(s[i]=='('){
                st.push(prev);
                curr*=prev;
                prev=1;
            }
            if(s[i]==')'){
                curr*=st.top();
                st.pop();
            }
           if(s[i]=='+'){ 
               prev=1;   
            }
            if(s[i]=='-'){ 
               prev=-1;   
            }

        }
        return sum;
    }
};