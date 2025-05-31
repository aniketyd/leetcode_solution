class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
         unordered_set<int>st;
         unordered_map<int ,int>mp;
         int cnt=0;
         for(int i=0;i<n;i++){
            if(i%2==0){
            for(int j=0;j<n;j++){
                cnt++;
                if(board[n-i-1][j]!=-1)
                mp[cnt]=board[n-i-1][j];
            }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    cnt++;
                    if(board[n-i-1][j]!=-1)
                    mp[cnt]=board[n-i-1][j];
                }
            }
         }
         queue<int>q;
        
         if(mp.find(1)!=mp.end())
        { q.push(mp[1]);
         st.insert(mp[1]);}
         else{
             q.push(1);
         st.insert(1);
         }
         int step=0;
         
         while(!q.empty()){
           int sz=q.size();
           for(int i=0;i<sz;i++){
             int val=q.front();
             if(val==n*n)return step;
             q.pop();
             for(int k=val+1;k<=val+6&&k<=n*n;k++){
                if(st.find(k)==st.end()){
                    
                    st.insert(k);
if(mp.find(k)!=mp.end()){
    q.push(mp[k]);
} else {
    q.push(k);
}

                }
             }
           }
           step++;
         }
         return -1;
    }
};