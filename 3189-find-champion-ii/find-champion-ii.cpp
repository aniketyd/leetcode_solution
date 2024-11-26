class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n+1);
        int m=edges.size();
        for(int i=0;i<m;i++){
            indegree[edges[i][1]]++;
        }
        int k=-1,c=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                c++;
                k=i;
            }
        }
        if(c==1)
        return k;
        return -1;
    }
};