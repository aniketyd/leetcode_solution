
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
unordered_set<string>ans;
    void fun(vector<vector<char>>&b,Trie &tr,int i,int j,string &str,Node *srch){
        int adjx[4]={1,0,-1,0};
        int adjy[4]={0,1,0,-1};
         int n=b.size();
        int m=b[0].size();
       
        if(srch->links[b[i][j]-'a']==NULL)return;
        str+=b[i][j];
        Node* srch2=srch->links[b[i][j]-'a'];
        if(srch2->f==true)ans.insert(str);
        char ch=b[i][j];
        b[i][j]='.';
        for(int q=0;q<4;q++){
            int x=i+adjx[q];
            int y=j+adjy[q];
            if(x>=0&&y>=0&&x<n&&y<m&&b[x][y]!='.'){
                fun(b,tr,x,y,str,srch->links[ch-'a']);
            }
        }
        b[i][j]=ch;
        str.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        Trie tr;
        int n=b.size();
        int m=b[0].size();
        int k=w.size();
        for(int i=0;i<k;i++){
            tr.insert(w[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string str="";
               fun(b,tr,i,j,str,tr.root);    
               }
            }
            vector<string>fans;
            for(auto &st:ans)
            fans.push_back(st);
            return  fans;
        }

    
};