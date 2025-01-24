class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       vector<vector<int>>g(graph.size());
       vector<int>indegree(graph.size());
       for(int i=0;i<graph.size();i++)
       {
           indegree[i]=graph[i].size();
           for(int j=0;j<graph[i].size();j++)
           {g[graph[i][j]].push_back(i);}
       }
       queue<int>q;
       vector<int>ans;
       for(int i=0;i<graph.size();i++)
       {
           if(indegree[i]==0)
           {
               q.push(i);
               ans.push_back(i);
           }
       }
       while(!q.empty())
       {
           int u=q.front();
           q.pop();
           for(auto val:g[u])
           {
               indegree[val]--;
               if(indegree[val]==0)
               {
                   q.push(val);
                   ans.push_back(val);
               }
           }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};