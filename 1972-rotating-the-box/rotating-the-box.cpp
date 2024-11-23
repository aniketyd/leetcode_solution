class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                if(box[i][j]=='#')c++;
                if(box[i][j]=='*'){
                    ans[j][n-1-i]='*';
                    for(int k=j-1;k>=0&&c>0;k--){
                        ans[k][n-1-i]='#';c--;
                    }
                    c=0;
                }
            }
            if(c){
                for(int k=m-1;k>=0&&c>0;k--){
                        ans[k][n-1-i]='#';c--;
                    }
            }
        }
        
        return ans;
    }
};