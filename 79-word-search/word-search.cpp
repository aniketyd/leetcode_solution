class Solution {
public:
    struct Node{
    int x,y;
    set<pair<int,int>>st;
    Node(int a,int b){
        x=a;
        y=b;
    }
};
  bool bf(vector<vector<char>>&v,string &word,int a,int b){
         int n=v.size();
        int m=v[0].size();
        int sz=word.size();
        int adjx[4]={0,1,-1,0};
        int adjy[4]={1,0,0,-1};
        queue<Node>q;
        Node f(a,b);
        f.st.insert({a,b});
        q.push(f);
        while(!q.empty()){
            Node top=q.front();
            q.pop();
            if(top.st.size()==sz)return true;
            for(int i=0;i<4;i++){
                int nx=adjx[i]+top.x;
                int ny=adjy[i]+top.y;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&(top.st.find({nx,ny})==top.st.end())&&(word[top.st.size()]==v[nx][ny])){
                    Node temp=top;
                    temp.x=nx;
                    temp.y=ny;
                    temp.st.insert({nx,ny});
                    q.push(temp);
                }
            }
        }
        return false;
  }
    vector<vector<int>> vis;
    int adjx[4] = {0, 1, -1, 0};
    int adjy[4] = {1, 0, 0, -1};
    int N, M, S;

    bool dfs(vector<vector<char>>& board, string &word, int x, int y, int idx) {
        if (idx >= S) return true;

        vis[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + adjx[i];
            int ny = y + adjy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M &&
                !vis[nx][ny] && board[nx][ny] == word[idx]) {
                if (dfs(board, word, nx, ny, idx + 1)) return true;
            }
        }

        vis[x][y] = 0; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        N = n; M = m; S = word.size();

        vis.resize(n, vector<int>(m, 0));  

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 1)) return true;
                }
            }
        }
        return false;
    }
};
