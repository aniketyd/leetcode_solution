class Solution {
public:
 struct Node {
    int val,x,y;

    
    Node(int _val, int _x, int _y) : val(_val), x(_x), y(_y) {}
};

struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.val > b.val; 
    }
};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q) {
        int n=grid.size();
        int m=grid[0].size();
        int adx[4]={0,1,0,-1};
        int ady[4]={1,0,-1,0};
        priority_queue<Node, vector<Node>, Compare> pq;
        vector<vector<int>>v(n,vector<int>(m,1e7));
        pq.push(Node(grid[0][0],0,0));
        v[0][0]=grid[0][0];
        while(!pq.empty()){
            auto it=pq.top();int x=it.x,y=it.y;pq.pop();
            if(it.val>v[x][y])continue;
            for(int i=0;i<4;i++){
                int nx=adx[i]+x;
                int ny=ady[i]+y;
                
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&v[nx][ny]>max(grid[nx][ny],it.val)){
                    v[nx][ny]=max(grid[nx][ny],it.val);
                    pq.push(Node(max(grid[nx][ny],it.val),nx,ny));
                }
            }
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]<=1e6){
                    mp[v[i][j]]++;
                }
            }
        }
        vector<pair<int,int>>anss;
        vector<int>ans;
        int sum=0;
        for(auto val:mp){
            sum+=val.second;
            anss.push_back({val.first,sum});
        }
        for(int i=0;i<q.size();i++){
           auto it = upper_bound(anss.begin(), anss.end(), make_pair(q[i], 0)) - anss.begin();
 
            if(it==0)
            ans.push_back(0);
            else{
                --it;
                ans.push_back(anss[it].second);
            }
        }
        return ans;

    }
};