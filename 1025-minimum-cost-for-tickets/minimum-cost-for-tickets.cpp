class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>v(366,0);
        for(int i=0;i<n;i++){
            v[days[i]]=1;
        }
        for(int i=1;i<=365;i++){
           
             if(v[i]==1){
                 v[i]=v[i-1]+costs[0];
                 if(i-7>=0)
                 v[i]=min(v[i],v[i-7]+costs[1]);
                 else
                 v[i]=min(v[i],costs[1]);
                 if(i-30>=0)
                 v[i]=min(v[i],v[i-30]+costs[2]);
                 else
                 v[i]=min(v[i],costs[2]);
             }
             else
             v[i]=v[i-1];

        }
        return v[365];
    }
};