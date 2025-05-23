class Solution {
public:
    int minimumMoves(vector<vector<int>>&grid){
        int n=grid.size(),ans=0;
        map<pair<int,pair<int,int>>,int>mp;
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{0,1}});
        mp[{0,{0,1}}]++;
        int i=0;
        while(q.size()>0){
            int m=q.size();
            while(m--)
            {
                int x=q.front().second.first,y=q.front().second.second,pos=q.front().first;
                q.pop();
                if(x==n-1 && y==n-1 && pos==0)return ans;
                if(pos==0)
                {
                    if(y+1<n && grid[x][y+1]==0 && mp.find({0,{x,y+1}})==mp.end()){
                        q.push({0,{x,y+1}});
                        mp[{0,{x,y+1}}]++;
                    }
                    if(x+1<n && grid[x+1][y]==0 && grid[x+1][y-1]==0 && mp.find({0,{x+1,y}})==mp.end()){
                        q.push({0,{x+1,y}});
                        mp[{0,{x+1,y}}]++;
                    }
                    if(x+1<n && grid[x+1][y]==0 && grid[x+1][y-1]==0 && mp.find({1,{x+1,y-1}})==mp.end()){
                        q.push({1,{x+1,y-1}});
                        mp[{1,{x+1,y-1}}]++;
                    }
                }else{
                    if(x+1<n && grid[x+1][y]==0 && mp.find({1,{x+1,y}})==mp.end()){
                        q.push({1,{x+1,y}});
                        mp[{1,{x+1,y}}]++;
                    }
                    if(y+1<n && grid[x][y+1]==0 && grid[x-1][y+1]==0 && mp.find({1,{x,y+1}})==mp.end()){
                         q.push({1,{x,y+1}});
                         mp[{1,{x,y+1}}]++;
                    }
                    if(y+1<n && grid[x][y+1]==0 && grid[x-1][y+1]==0 && mp.find({0,{x-1,y+1}})==mp.end()){
                         q.push({0,{x-1,y+1}});
                         mp[{0,{x-1,y+1}}]++;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};