struct Node{
    Node* links[26];
    bool f=false;
};
class Trie {
   public:
   Node* root=new Node();
  
   void insert(string s){
    int n=s.size();
    Node* nd=root;
    for(int i=0;i<n;i++){
       if(nd->links[s[i]-'a']==NULL)
       nd->links[s[i]-'a']=new Node();
       nd=nd->links[s[i]-'a'];
    }
    nd->f=true;
   }
};
class Solution {
public:
    vector<int>dp;
    bool fun(string s, int i,Trie &tr){
        if(i==s.size())return true;
        if(dp[i]!=-1)return dp[i];
        Node* srch=tr.root;

        while(i<(int)s.size()&&srch->links[s[i]-'a']!=NULL){
            if(srch->f==true){
                if(fun(s,i,tr))return dp[i]=true;
            }
            srch=srch->links[s[i]-'a'];i++;
        }
         if(srch->f==true){
                if(fun(s,i,tr))return dp[i]=true;
            }
       
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& w) {
        int n=s.size();
        int m=w.size();
        Trie tr;
        for(int i=0;i<m;i++){
            tr.insert(w[i]);
        }
        dp.resize(n+1,-1);
       return fun(s,0,tr);
    }
};