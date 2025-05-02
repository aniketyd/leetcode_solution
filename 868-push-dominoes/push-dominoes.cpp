class Solution {
public:
    string pushDominoes(string d) {
      
        int n=d.size();
          string ans(n,'.');
        
        vector<int>v(n,1e9);
        int l=-1,r=-1;
        for(int i=0;i<n;i++){
           if(d[i]=='R')
           r=i;
           if(d[i]==
        'L')
        l=i;
           if(r>l){
            ans[i]='R';
            v[i]=i-r;
           }
           else
           ans[i]='.';
        }
        l=-1,r=1e9;
        for(int i=n-1;i>=0;i--){
              if(d[i]=='R')
           r=i;
           if(d[i]==
        'L')
        l=i;
           if(l<r&&v[i]>(l-i)&&l!=-1){
            ans[i]='L';
           }
           else if(l!=-1&&l<r&&v[i]==(l-i))
           ans[i]='.';
        
        }
        return ans;
      
    }
};