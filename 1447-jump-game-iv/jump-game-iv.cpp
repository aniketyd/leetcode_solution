class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        mp[arr[i]].push_back(i);
  int c=0;
       queue<int>q;
       q.push(0);
       vector<int>vis(n,0);
       while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            int ci=q.front();
            if(ci==n-1)return c;
            q.pop();
            if(ci-1>=0&&vis[ci-1]==0){
            q.push(ci-1);vis[ci-1]=1;
            }
            if(ci+1<n&&vis[ci+1]==0){
                q.push(ci+1);vis[ci+1]=1;
            }
            while(mp[arr[ci]].size()>0){
                int k=mp[arr[ci]].back();
                if(vis[k]==0){
                    q.push(k);
                    vis[k]=1;
                }
                mp[arr[ci]].pop_back();
            }
        }
        c++;
       }
       return 0;
    }
};