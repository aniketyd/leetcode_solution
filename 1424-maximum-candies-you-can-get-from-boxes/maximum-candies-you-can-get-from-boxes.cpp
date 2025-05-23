class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
       
     int n=status.size();
     vector<int>visited(n);
     unordered_set<int>st;
     queue<int>q;
     for(int i=0;i<initialBoxes.size();i++){
        if(status[initialBoxes[i]])
       { q.push(initialBoxes[i]);}
        else
        st.insert(initialBoxes[i]);
        visited[initialBoxes[i]]=1;
     }
     int sum=0;
     while(!q.empty()){
        int nd=q.front();
        q.pop();
        sum+=candies[nd];
        for(auto keynd:keys[nd]){
            status[keynd]=1;
            if(st.find(keynd)!=st.end())
           { q.push(keynd);st.erase(st.find(keynd));}
        }
        for(auto adjnd:containedBoxes[nd]){
             if(visited[adjnd]==0){
                visited[adjnd]=1;
                if(status[adjnd]==0)
                st.insert(adjnd);
                else
                q.push(adjnd);
             }
        }

     }
     return sum;

    }
};